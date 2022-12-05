#include <iostream>
#include "BST.h"
#include "UnableToInsertException.h"

using std::cout;
using std::endl;

int main(){

    BST* newBST =  new BST();

    // test case 1 inserting 6 elements into the BST 5,4,6,3,7

    cout << "Test case 1: inserting elements 5,4,6,3,7 into the BST" << endl;

    try{
        cout << "inserting element " << 5 << endl;
        newBST->insert(5);
    }
    catch(UnableToInsertException & anException){
        cout << "insert failed because " << anException.what() << endl;

    }

    try{
        cout << "inserting element " << 4 << endl;
        newBST->insert(4);
    }
    catch(UnableToInsertException & anException){
        cout << "insert failed because " << anException.what() << endl;

    }

    try{
        cout << "inserting element " << 6 << endl;
        newBST->insert(6);
    }
    catch(UnableToInsertException & anException){
        cout << "insert failed because " << anException.what() << endl;

    }
    try{
        cout << "inserting element " << 3 << endl;
        newBST->insert(3);
    }
    catch(UnableToInsertException & anException){
        cout << "insert failed because " << anException.what() << endl;

    }
    try{
        cout << "inserting element " << 7 << endl;
        newBST->insert(7);
    }
    catch(UnableToInsertException & anException){
        cout << "insert failed because " << anException.what() << endl;

    }     

    cout << "end of test 1." << endl;

    cout << "Test case 2: printing out the BST" << endl;

    try{
        cout << "Printing out the BST" << endl;
        newBST->printInOrder();
        cout << endl;
    }
    catch(UnableToInsertException & anException){
        cout << "printInOrder() failed because " << anException.what() << endl;
    }

    cout << "End of test case 2." << endl;

    // test 3 checking for the number of nodes in the BST
    cout << "Test case 3: checking for the node count:" << endl;

    try{
        cout << "checking for the number of nodes." << endl;
        cout << "Excepted result: 5." << endl;
        cout << "Actual result: " << newBST->numberOfNodes() << endl;
    }   
    catch(UnableToInsertException & anException){
        cout << "numberOfNode() failed because " << anException.what() << endl;
    }

    cout << "end of test 4." << endl;

    // Test case 4: checking the height of the BST
    cout << "Test case 4: testing for the height of the BST." << endl;

    try{
        cout << "Checking for the height of the BST" << endl;
        cout << "Expected result: 3" << endl;
        cout << "Actual result: " << newBST->height() << endl;
    }
    catch(UnableToInsertException& anException){
        cout << "height() failed because " << anException.what() << endl;
    }

    // Test case 5: removing the element 7 from the BST

    cout << "Test case 5: removing the element 7 from the BST" << endl;
    
    try{
        cout << "removing element 7:" << endl;
        cout << "Expected result: { 3 4 5 6 }" << endl;
        newBST->remove(3);
        cout << "Actual Results: ";
        newBST->printInOrder();
        cout << endl;
    }
    catch(UnableToInsertException& anException){
        cout << "height() failed because " << anException.what() << endl;
    }   

    cout << "End of test 5." << endl;
    

    // Test case 6

    cout << "Test case 6: finding element 3 in the BST" << endl;

    try{
        cout << "Searching for the element 3 in the BST" << endl;
        cout << "Expected result: Element 3 was found in the BST." << endl;
        cout << "Actual result: ";
        if(newBST->search(3)){
            cout << " Element 3 was found in the BST." << endl;
        }
        else{
            cout << " Not found in the BST." << endl;
        }
    }

    catch(UnableToInsertException& anException){
        cout << "height() failed because " << anException.what() << endl;
    }

    cout << "End of test 6." << endl;

    return 0;
}