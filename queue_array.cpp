#include <iostream>
using namespace std;
template <typename T>
class queue_array{
    private:
        int queue_capacity;
        int head, tail;
        int queue_size;
        T* queue_arr;
    public:
        queue_array(int size = 10): queue_capacity(size){
            head = 0;
            tail = 0;
            queue_size = 0;
            queue_arr = new T[queue_capacity];
        }
        ~queue_array(){
            delete[] queue_arr;
        }
        bool isempty(){
            return queue_size == 0;
        }
        void enqueue(T x){
            if(queue_size == queue_capacity)
                cout << "Queue is full, enqueue failed...\n";
            else{
                queue_arr[tail] = x;
                tail = (tail + 1) % queue_capacity;
                ++queue_size;
            }
        }
        T dequeue(){
            if(isempty()){
                cout << "Queue is empty, dequeue failed...\n";
            }
            else{
                T temp = queue_arr[head];
                head = (head + 1) % queue_capacity;
                --queue_size;
                return temp;
            }
        }
        void travel_queue(){
            if(isempty())
                cout << "queue is empty, nothing to display...\n";
            else{
                int i = head;
                cout << "Queue display...\n";
                int q = queue_size;
                while(q-- > 0){
                    cout << queue_arr[i] << endl;
                    i = (i + 1) % queue_capacity;
                }
            }
        }
};
int main(){
    queue_array<int> lt;
    for(int i = 0; i < 10; i++)
        lt.enqueue(i);
    lt.travel_queue();
    cout << "dequeue " << lt.dequeue() << endl;
    lt.travel_queue();
    cout << "dequeue " << lt.dequeue() << endl;
    lt.travel_queue();
    lt.enqueue(100);
    lt.travel_queue();
    return 0;
}







