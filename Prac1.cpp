#include<bits/stdc++.h>
using namespace std;

void menu(){
    cout<<"\n\tMENU : \n";
    cout<<"Press 1 to traverse the array\n"
        <<"Press 2 to insert an element\n"
        <<"Press 3 to delete an element\n"
        <<"Press 4 to search an element using linear search\n"
        <<"Press 5 to search an element using binary search\n"
        <<"Press 6 to sort an array using insertion sort\n"
        <<"Press 7 to exit\n";
}

void arrayTraversal(int *arr, int n){
    if(n == 0) cout<<"The array is empty.";
    else{
        cout<<"\n These elements of the array : \n";
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
    }
    } 
}

int arrayInsertion(int *arr, int n){
    int elem, pos;
    cout<<"Enter the element you want to insert : ";
    cin>> elem;
    cout<<"Enter the position at which you want to enter the element : ";
    cin>>pos;
    if(pos < 1 || pos > n+1) cout<<"Invalid position. Position out of bounds";

    else if(pos == n+1) { arr[n] = elem; return n+1; }
    else if(pos == 1){
        for(int i=n-1; i>=0; i--){
            arr[i+1] = arr[i];
        }
        arr[0] = elem;
        return n+1;
    }
    else{
        for(int i=n; i>=pos ; i--){
            arr[i] = arr[i-1];
        }
        arr[pos-1] = elem;
        return n+1;
    }
    return n;
}

int arrayDeletion(int *arr, int n){
    int elem;
    cout<<"Enter the element you want to delete : ";
    cin>>elem;
    int i;
    for( i=0; i<n; i++){ 
        if(elem == arr[i]) break;
    } 
    if(i < n){ 
        for(int j=i; j<n; j++){
            arr[j] = arr[j+1]; 
        }
        n = n-1;   
        // cout<<"Inside if "<<n<<endl;
    }else{
        cout<<"Element not found."<<endl;
    }
    // cout<<"Outside loop : "<<n<<endl;
    return n;
}

void arrayLinearSearch(int *arr, int n){
    int elem;
    cout<<"Enter the element you want to search : ";
    cin>>elem;
    for(int i=0 ; i<n ; i++){
        if(elem == arr[i]) {
            cout<<"Element present at index "<<i; 
            return;
        }
    }
    cout<<"Element not found";
}

int arrayBinarySearch(int *arr, int n, int beg, int end, int elem){
    sort(arr, arr+n);
    if(beg <= end){
        int mid = beg+(end-beg)/2;
        if(elem == arr[mid])
            return mid;
        else if(elem > arr[mid])
            return arrayBinarySearch(arr, n, mid+1, n, elem);
            return arrayBinarySearch(arr, n, 0, mid-1, elem);
    }
    return -1;
}

void arrayInsertionSort(int *arr, int n){

    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = key;
    }

}

int main(){

    int n, choice;
    int  arr[10];
    cout<<"The maximum size of array is 10"<<endl;
    cout<<"Enter size of the array : ";
    cin>>n;
    if(n > 10) {
        cout<<"Overflow";
        return 0;
    }

    cout<<"Enter elements of the array : ";
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }

    do{
        menu();
        cout<<"\nEnter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
                arrayTraversal(arr, n);
                break;
            case 2: {
                cout<<"The current size before insertion is: "<<n<<endl;
                if(n < 10) n = arrayInsertion(arr, n);
                else cout<<"Array size is full";
                break;
                }
            case 3:{
                cout<<"The current size before deletion is: "<<n<<endl;
                if(n > 0) n = arrayDeletion(arr, n);
                else cout<<"Array is empty";
                break;
                }
            case 4: 
                arrayLinearSearch(arr, n);
                break;
            case 5: {
                int toSearch;
                cout<<"Enter the element you want to search: ";
                cin>>toSearch;
                int idx = arrayBinarySearch(arr, n, 0, n-1, toSearch);
                if (idx == -1)
                    cout << "Element not found";
                else
                    cout << "Element found at index " << idx;
                break;
            }
            case 6: 
                arrayInsertionSort(arr, n);
                break;
            case 7:
                exit(0);
                break;
            default: 
                cout<<"Invalid Choice";

        }

    }while(choice != 7);

    return 0;
}