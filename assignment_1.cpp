#include<iostream>
using namespace std;
// char choice='y';
// string array[]={"create","display","insert","delete","search","exit"};
// int option;
// int main_arr[100];
// int size=0;
// int main(){
//     while (choice == 'y'){
//         cout << "what operation do you want to perform? enter number " << endl;
//         for(int i=0;i<6;i++){
//             cout << i+1 << " : " << array[i] << endl;
//         }
//         cin >> option;
//         if (option<1 && option>6){
//             cout << "enter valid input" << endl;
//         }
//         if (option==1){
//             int n;
//             cout << "enter size of array to be created" << endl;
//             cin >> n;
//             size=n;
//             for(int i=0;i<n;i++){
//                 int num;
//                 cout << "enter input integers"<< endl;
//                 cin >> num;
//                 main_arr[i]=num;
//             }
//         }
//         else if(option==2){
//             for(int i=0;i<size;i++){
//                 cout << main_arr[i]<<" ";
//             }
//             cout << endl;
//             //choice='n';
//         }
//         else if(option==3){
//             int num,pos;
//             cout << "enter position"<<endl;
//             cin >> pos;
//             cout << "enter number to be inserted" << endl;
//             cin >> num;
//             for (int i=size;i>pos;i--){
//                 main_arr[i]=main_arr[i-1];
//             }
//             main_arr[pos]=num;
//             size++;
//         }
//         else if(option==4){
//             int pos;
//             cout << "enter pos to delete" << endl;
//             cin >> pos;
//             for(int i=pos;i<size;i++){
//                 main_arr[i]=main_arr[i+1];
//             }
//             size--;
//         }
//         else if(option==5){
//             int num;
//             cout << "enter number to find" << endl;
//             cin >> num;
//             int found=0;
//             for(int i=0;i<size;i++){
//                 if(main_arr[i]==num){
//                     found=1;
//                     cout << "number found at " << i+1 <<"th position"<< endl;
//                     break;
//                 }
                
//             }
//             if (found==0){
//                     cout << "element not found";
//                 }
//         }
//         else if(option==6){
//             cout <<"thank you for your time!!";
//             choice='n';
//         }
//     }
// }

// int main_arr[]={1,2,3,1,2,4,5,5,3,1,6,5,2,4};

// void del(int array[],int size,int index){
//     for(int i=index;i<size;i++){
//         array[i]=array[i+1];
//     }
    
// }
// int main(){
//     int size= sizeof(main_arr)/4;
//     for (int i=0;i<size-1;i++){
//         for(int j=i+1;j<size;j++){
//             if (main_arr[i]==main_arr[j]){
//                 del(main_arr,size,j);
//                 size--;
//             }
//         }
//     }
//     for (int i=0;i<size;i++){
//         cout << main_arr[i] << " ";
//     }
    
// }

//output: 10000

// int arr[]={1,2,3,4,5};
// int arr2[2][3]={{1,2,3},{4,5,6}};

// int main(){
//     for(int i=0;i<(sizeof(arr)/8);i++){
//         int temp=arr[i];
//         arr[i]=arr[sizeof(arr)/4-1-i];
//         arr[sizeof(arr)/4-1-i]=temp;
//     }
//     for(int i=0;i<sizeof(arr)/4;i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     for(int i=0;i<1;i++){
//         for(int j=0;j<3;j++){
//             int temp=arr2[i][j];
//             arr2[i][j]=arr2[1-i][j];
//             arr2[1-i][j]=temp;
//         }
//     }
//     for(int i=0;i<2;i++){
//         for(int j=0;j<1;j++){
//             int x= arr2[i][3-1-j];
//             arr2[i][3-1-j]=arr2[i][j];
//             arr2[i][j]=x;
//         }
//     }
//     for(int i=0;i<2;i++){
//         for(int j=0;j<3;j++){
//             cout << arr2[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main(){
//     int arr1[3][3]={{1,1,1},{1,1,1},{1,1,1}};
//     int arr2[3][3]={{2,2,2},{2,2,2},{2,2,2}};
//     int arr3[3][3];
//     for (int i=0;i<3;i++){
//         for (int j=0;j<3;j++){
//             int sum=0;
//             for (int k=0;k<3;k++){
//                     sum+=arr1[i][k]*arr2[k][j];
//             }
//             arr3[i][j]=sum;
//         }
//     }
//     for (int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cout << arr3[i][j]<<" ";
//         }
//         cout << endl;
//     }
// }
// int main(){
//     int arr3[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//     for(int i=0;i<3;i++){
//         for(int j=i+1;j<3;j++){
//             int temp=arr3[i][j];
//             arr3[i][j]=arr3[j][i];
//             arr3[j][i]=temp;
//         }
//     }
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cout << arr3[i][j]<<" ";
//         }
//         cout << endl;
//     }
// }
int main(){
    int arr3[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int sum_cols[3];
    int sum_rows[3];
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=arr3[i][j];
        }
        sum_rows[i]=sum;
    }
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=arr3[j][i];
        }
        sum_cols[i]=sum;
    }
    for(int i=0;i<3;i++){
        cout << sum_rows[i]<< " ";
    }
    cout << endl;
    for(int i=0;i<3;i++){
        cout << sum_cols[i]<< " ";
    }
    cout << endl;
    
    
    

}
