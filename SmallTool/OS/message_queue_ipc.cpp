#include <bits/stdc++.h>
#include <unistd.h>
#include <boost/lexical_cast.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/ipc/message_queue.hpp>
using namespace::std;
using namespace boost::interprocess;

int main()
{
    int pid;
    while((pid = fork()) == -1);

    if(pid != 0){ // father
        message_queue::remove("message_queue");
        message_queue mq(create_only, "message_queue", 100, sizeof(int));
        for(int i = 0; i <= 65535; i++){
            cout << "father>\tHello-" << i << '\n';
            mq.send(&i, sizeof(i), 0);
            sleep(rand()%3+1);
        }
    }else{ // child
        message_queue mq(open_only, "message_queue");
        unsigned int priority;
        message_queue::size_type recvd_size;
        for (int i = 0; i <= 65535; i++) {
            int number;
            mq.receive(&number, sizeof(number),recvd_size,priority);
            if (number != i || recvd_size != sizeof(number))
                return 1;
            else
                cout << "son>\tHello-" << number << '\n';
        }
        message_queue::remove("message_queue");
    }

    return 0;
}
