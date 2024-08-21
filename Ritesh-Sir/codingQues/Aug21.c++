// Reverse a linked lists using Recursion + iteration
// Merge Two Sorted Linked Lists
// Single Number II --> link : https://leetcode.com/problems/single-number-ii/description/
// Search in rotated Sorted Array --> link :  https://leetcode.com/problems/search-in-rotated-sorted-array/description/


// Search in Rotated Sorted Array
// #include <iostream>
// #include <vector>
// using namespace std;
// int Search(vector<int> &arr, int target){
//     if(arr.size() == 1 && arr[0] == target){
//         return 0;
//     }

//     int s = 0;
//     int e = arr.size()-1;
//     int mid = s + (e - s)/2;

//     while(s <= e){
//         if(arr[mid] == target){
//             return mid;
//         }
//         else if(arr[s] <= arr[mid]){
//             if(arr[s] <= target && target < arr[mid]){
//                 e = mid - 1;
//             }
//             else{
//                 s = mid + 1;   
//             }
//         }
//         else{
//             if(arr[mid] < target && target <= arr[e]){
//                 s = mid + 1;
//             }
//             else{
//                 e = mid - 1;
//             }
//         }
//         mid = s + (e - s)/2;
//     }

//     return -1;
// }
// int main(){
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for(int i = 0; i<n; i++){
//         cin >> arr[i];
//     }

//     int target;
//     cin >> target;

//     cout << Search(arr, target) << endl;

//     return 0;
// }

// Merge Two Sorted Linked Lists
// #include <iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data){
//         this -> data = data;
//         this -> next = NULL;
//     }
// };
// void InsertAtTail(Node* &tail, Node* &head, int data){
//     if(tail == NULL){
//         Node* temp = new Node(data);
//         head = temp;
//         tail = temp;
//     }
//     else{
//         Node* temp = new Node(data);
//         tail -> next = temp;
//         tail = tail -> next;
//     }
// }
// void Display(Node* &head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout << temp -> data << " ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// Node* solve(Node* head1, Node* head2){
//     if(head1 -> next == NULL){
//         head1 -> next = head2;
//         return head1;
//     }

//     Node* curr1 = head1;
//     Node* next1 = head1 -> next;
//     Node* curr2 = head2;
//     Node* next2 = head2 -> next;

//     while(next1 != NULL && curr2 != NULL){
//         if((curr2->data >= curr1->data) && (curr2->data <= next1 -> data)){
//             curr1 -> next = curr2;
//             next2 = curr2 -> next;
//             curr2 -> next = next1;

//             curr1 = curr2;
//             curr2 = next2;
//         }
//         else{
//             curr1 = next1;
//             next1 = next1 -> next;

//             if(next1 == NULL){
//                 curr1 -> next = curr2;
//                 return head1;
//             }
//         }
//     }

//     return head1;
// }

// void MergeTwoLL(Node* &head1, Node* &head2){
//     if(head1 == NULL){
//         Display(head2);
//         return;
//     }
//     if(head2 == NULL){
//         Display(head1);
//         return;
//     }

//     Node* res = NULL;
//     if(head1 -> data <= head2 -> data){
//         res = solve(head1, head2);
//     }
//     else{
//         res = solve(head2, head1);
//     }

//     Display(res);
// }
// int main(){
//     int n; // Number of nodes in ll1
//     cin >> n; 

//     Node* head1 = NULL;
//     Node* tail1 = NULL;
//     for(int i = 0; i<n; i++){
//         int data;
//         cin >> data;
//         InsertAtTail(tail1, head1, data);
//     }   

//     int m; // Number of nodes in ll2
//     cin >> m;

//     Node* head2 = NULL;
//     Node* tail2 = NULL;
//     for(int i = 0; i<m; i++){
//         int data;
//         cin >> data;
//         InsertAtTail(tail2, head2, data);
//     }

//     MergeTwoLL(head1, head2);
    
//     return 0;
// }


// Reverse Linked List using Rec + Iteration
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
void InsertAtTail(Node* &tail, Node* &head, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = tail -> next;
    }
}
void Display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void Reverse1(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forw = head;
    while(curr != NULL){
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }
    Display(prev);
}

Node* Reverse2(Node* head, Node* &ans) {
    if(head == NULL || head->next == NULL) {
        ans = head;  
        return head;
    }

    Node* temp = Reverse2(head->next, ans);
    temp->next = head;  
    head->next = NULL; 

    return head;  
}


int main(){
    int n; // Number of nodes in ll1
    cin >> n; 

    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0; i<n; i++){
        int data;
        cin >> data;
        InsertAtTail(tail, head, data);
    }   

    Reverse1(head);  // Using Iteration

    Node* ans = NULL;
    Node* temp = Reverse2(head, ans); // Using Recursion
    Display(ans);
    
    return 0;
}