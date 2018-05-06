#include "arraydatabase.h"

//vector first names



//helper function
void merge( database &arr, int left, int middle, int right){

}


arrayDatabase::arrayDatabase(){

    this->list_size = 0;
}

void arrayDatabase::createDatabase(int rooms)
{
    this->list.resize(rooms);
    this->list_size = rooms;

    for(unsigned int i=0; i<this->list.size(); i++){

       this->list[i].name = "Customer Name";  // Will add file to save random names
        this->list[i].phone_num  = this->phone_gen();
        this->list[i].room_price = this->bell_curve_generator();
        this->list[i].room_num = i;
    }
}


double arrayDatabase::bell_curve_generator()
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::normal_distribution<double> distrN(350.0, 12.0);
    double ran_num = distrN(e);

    return ran_num;
}


void arrayDatabase::changePrice()
{

    for(int i=0; i<this->list_size; i++){
        this->list[i].room_price = bell_curve_generator();
    }
}



void arrayDatabase::print_database()
{

    for(int i=0; i<this->list_size; i++){
        std::cout<<"\nRecord # "<< i+1<<std::endl;
        std::cout<<this->list[i].name<<std::endl;
        std::cout<<this->list[i].phone_num<<std::endl;
        std::cout<<this->list[i].room_num<<std::endl;
        std::cout<<this->list[i].room_price<<std::endl;

    }
    std::cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}




void arrayDatabase::insertionSort(int option)
{
    if(option == 1){
        int i, j;
        ListNode key;
        for(i=0; i<this->list_size; i++){
            key = this->list[i];
            j = i-1;

            while(j>= 0 && this->list[j].phone_num>key.phone_num)
            {
                this->list[j+1] = this->list[j];
                j=j-1;
            }

            this->list[j+1] = key;
        }
    }

    else if(option == 2){

        int i, j;
        ListNode key;
        for(i=0; i<this->list_size; i++){
            key = this->list[i];
            j = i-1;

            while(j>= 0 && this->list[j].room_num>key.room_num)
            {
                this->list[j+1] = this->list[j];
                j=j-1;
            }

            this->list[j+1] = key;
        }

    }

    else if(option == 3){
        int i, j;
        ListNode key;
        for(i=0; i<this->list_size; i++){
            key = this->list[i];
            j = i-1;

            while(j>= 0 && this->list[j].name>key.name)
            {
                this->list[j+1] = this->list[j];
                j=j-1;
            }

            this->list[j+1] = key;
        }
    }
    else {
        int i, j;
        ListNode key;
        for(i=0; i<this->list_size; i++){
            key = this->list[i];
            j = i-1;

            while(j>= 0 && this->list[j].room_price>key.room_price)
            {
                this->list[j+1] = this->list[j];
                j=j-1;
            }

            this->list[j+1] = key;
        }
    }
}

void arrayDatabase::selectionSort(int option)
{
    int i, j;
    int min_index;
    ListNode temp;

    if(option == 1){

        for(i=0; i<this->list_size-1; i++){

            min_index = i;

            for(j=i+1; j<this->list_size; j++){

                if(this->list[j].phone_num< this->list[min_index].phone_num){
                    min_index = j;
                }

            temp = this->list[min_index];
            this->list[min_index] = this->list[i];
            this->list[i] = temp;
            }
        }
    }

    else if(option == 2){

        for(i=0; i<this->list_size-1; i++){

            min_index = i;

            for(j=i+1; j<this->list_size; j++){

                if(this->list[j].room_num< this->list[min_index].room_num){
                    min_index = j;
                }

            temp = this->list[min_index];
            this->list[min_index] = this->list[i];
            this->list[i] = temp;
            }
        }
    }

    else if(option == 3){
        for(i=0; i<this->list_size-1; i++){

            min_index = i;

            for(j=i+1; j<this->list_size; j++){

                if(this->list[j].name < this->list[min_index].name){
                    min_index = j;
                }

            temp = this->list[min_index];
            this->list[min_index] = this->list[i];
            this->list[i] = temp;
            }
        }
    }
    else{
        for(i=0; i<this->list_size-1; i++){

            min_index = i;

            for(j=i+1; j<this->list_size; j++){

                if(this->list[j].room_price < this->list[min_index].room_price){
                    min_index = j;
                }

            temp = this->list[min_index];
            this->list[min_index] = this->list[i];
            this->list[i] = temp;
            }
        }
    }
}

void arrayDatabase::mergeSort(int l, int r)
{

}

//helper function
int partition(database &arr, int low, int high)
{

}


void arrayDatabase::randomizedQuickSort(int low, int high)
{

}







