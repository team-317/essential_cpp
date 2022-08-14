#include <thread>
#include<string>
#include<iostream>
using namespace std;

typedef int widget_id;
typedef string widget_data;
void update_data_for_widget(widget_id w, widget_data &data){
    cout << w << data;
}
void oops_again(widget_id w)
{
    widget_data data;
    std::thread t(update_data_for_widget, w, data);
    // display_status();
    // t.join();
    // process_widget_data(data);
}

int main(){
    widget_id w=20;
    oops_again(w);
    return 0;
}