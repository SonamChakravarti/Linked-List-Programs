/* 
 * File:   main.cpp
 * Author: Sona
 *
 * Created on January 19, 2014, 3:01 PM
 */

#include <cstdlib>
#include<iostream>
#include<string.h>
#include<string>
#include<strings.h>
#include<stdio.h>


using namespace std;

struct Node{
    int x;
    Node *next;
    
};

class Action{
    
};
int main() {
    int option,num;
    Node* root;
    Node* conductor;
    Node* conductor1;
    Node* temp;
    root= new Node;
    root->next =0;
    root->x=0;
    conductor=root;
    temp=new Node;
   // conductor1=root;
    int n;
    cout<<"Enter the option for action to be perfumed"<<endl;
    cout<<"1. Create Linked list (mandatory) \n2. Find nth to last element \n3. Copy and remove duplicate values \n"
            "4. Find loop in linked list \n5. Delete a node in between a linked list"<<endl;
    cin>>option;
    switch(option){
        case 1: {
            int j;
            for(j=0;j<10;j++){
               num=rand()%10;
               cout<<num<<endl;
               conductor->next = new Node;  // Creates a node at the end of the list
               conductor = conductor->next;// Points to that node
               conductor->next = 0;        
               conductor->x = num;
            }
            conductor=root;
            for(j=0;j<10;j++){    
               cout<<conductor->x<<endl;
               conductor = conductor->next;// Points to that node             
            }
            //break;
        }
        case 2:{
            cout<<"Enter the nth element to be found"<<endl;
            cin>>n;
            conductor=root;
            conductor1=conductor;
            int i;
            for(i=0;i<n;i++){
                conductor=conductor->next;
            }
            while(conductor->next!=NULL){
                conductor1=conductor1->next;
                conductor=conductor->next;
            }
            cout<<conductor1->x;
           // break;
            
        }
        case 3:{
            int index=10,i,val;
            int* arr=new int[index];
            for(i=0;i<index;i++){
                arr[i]=0;
            }
            conductor=root;
            while(conductor->next!=NULL){
                conductor=conductor->next;
                if(index<conductor->x){
                    for(i=0;i<(conductor->x-index);i++)
                    {
                        index=index+1;
                        arr[index]=0;
                    }                    
                }
                val=conductor->x;
                arr[val]++;
            }
            for(i=0;i<index;i++){
                if(arr[i]>1)
                    cout<<i<<"              "<<arr[i]<<endl;
            }
            break;
           
        }
        case 4:{
             int j;
            for(j=0;j<7;j++){
               num=rand()%10;
               cout<<num<<endl;
               conductor->next = new Node;  // Creates a node at the end of the list
               conductor = conductor->next;// Points to that node
               conductor->next = 0;        
               conductor->x = num;
               if(j==2)
                   temp=conductor;
            }
             conductor->next=temp;
             conductor=root;
             conductor1=conductor;
             while(true){
                 conductor=conductor->next;
                 conductor1=conductor1->next->next;
                 if(conductor==conductor1)
                     break;
             }
             conductor=root;
             while(conductor->next!=conductor1->next){
                 conductor=conductor->next;
                 conductor1=conductor1->next;                 
             }
            
             cout<<"Loop at: "<<conductor1->next->x<<endl;
             break;
        }
        case 5:{
             int j,del;
             for(j=0;j<10;j++){
               num=rand()%10;
               cout<<num<<endl;
               conductor->next = new Node;  // Creates a node at the end of the list
               conductor = conductor->next;// Points to that node
               conductor->next = 0;        
               conductor->x = num;
            }
             conductor=root;
             cout<<"Enter the node number to be deleted"<<endl;
             cin>>del;
             conductor=root;
             for(j=0;j<del;j++){
                 conductor=conductor->next;
                 
             }
             conductor->x=conductor->next->x;
             conductor->next=conductor->next->next;
             conductor=root;
             while(conductor->next!=NULL){    
               cout<<conductor->x<<endl;
               conductor = conductor->next;// Points to that node             
            }
             
            break;
        }
        default: cout<<"wrong option chosen"<<endl;
    }
    return 0;
}

