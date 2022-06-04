#include <QCoreApplication>
#include <QtGui/QGuiApplication>
#include <presage.h>
#include <iostream>

/* Simple example callback that tracks past context with a string.
 *
 * Using a callback object decouples the user application from the
 * chosen text buffer (which could be a simple string, a graphical
 * text widget, a file stream, etc.) and frees the caller from having
 * to explicitly notify of any updates to the context. Presage will
 * invoke on the callback whenever access to contextual data is
 * required.
 *
 */
using namespace std;
class ExampleCallback : public PresageCallback
{
public:
    ExampleCallback(const std::string& _past_context) : past_context(_past_context) { }
    std::string get_past_stream() const { return past_context; }
    std::string get_future_stream() const { return empty; }
private:
    const std::string& past_context;
    const std::string empty;
};
//int main(int argc, char** argv)


int main(int argc, char*argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    std::string context;
    ExampleCallback callback(context);
    QString dbPath="/home/candy/Documentos/presage_teste/portugues/presage_portuguese.xml";
    Presage *presage= new Presage(&callback);//, std::string(dbPath.toUtf8().constData()));

    std::string buffer;
    std::vector< std::string > predictions;
    for (;;) {
        // prompt user and append line into context buffer
        std::cout<< "> ";
        getline(std::cin, buffer);
        context += buffer;
        std::cout<<"context "<<context<<"\n";
        // request prediction
        predictions = presage->predict();
        // print predictions
        std::cout<<"prediction size: "<<predictions.size()<<"\n";
        for (int i = 0; i < predictions.size(); i++) {
            std::cout << predictions[i] << std::endl;
        }
    }

    //return 0;
    return app.exec();
}
