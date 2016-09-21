#include "Splash.h"
#include <thread>
#include <chrono>
#define __NOISY

FILE * f;

static void server_thread(){
    char buffer[1024];
    while(fgets(buffer, 1024, f)){
#ifdef __NOISY
        std::cout << buffer;
#endif
    }
}

bool Wicher::Splash::run_server(){
#ifdef WIN
    f = popen(".\\bin\\local_server.exe", "r");
#elif defined(UNI)
    f = popen("bin/local_server", "r");
#endif
    if(!f){
        pclose(f);
        return false;
    }
    //boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::thread t(&server_thread);
    return true;
}
