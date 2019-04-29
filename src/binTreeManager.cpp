#include "../headers/binTreeManager.h"

using namespace std;
binTreeManager::binTreeManager()
{
    cout << "| STARTING BINTREE MANAGER" << endl;
    this->addData(10);
    this->addData(20);
    this->addData(9);
    this->addData(1);
    this->addData(6);
    this->addData(8);
    this->addData(1);
    this->addData(0);
//    this->print(this->tree);

//    cout << "INORDER" << endl;
//
//    this->inOrder(this->tree);
//
//    cout << endl << "PREORDER" << endl;
//
//    this->preOrder(this->tree);
//
//    cout << endl << "POSTORDER" << endl;
//
//    this->postOrder(this->tree);

    cout << endl;

    this->autoBalance(this->tree);

}

binTreeManager::~binTreeManager()
{
    cout << "| TY GOODBYE!" << endl;

}

void binTreeManager::addData(int data) {

    if (this->tree != NULL) {
        this->addData(data, this->tree);
    } else {
        this->tree = new binTree;
        this->tree->data = data;
        this->tree->left = NULL;
        this->tree->right = NULL;
    }

}

void binTreeManager::addData(int data, binTree* bTree){

	if(data < bTree->data){
		if(bTree->left != NULL) {
			this->addData(data, bTree->left);
		} else {
			bTree->left = new binTree;
			bTree->left->data = data;
			bTree->left->left = NULL;
			bTree->left->right = NULL;
		}
	}

	if(data >= bTree->data){
		if(bTree->right != NULL) {
			this->addData(data, bTree->right);
		} else {
			bTree->right = new binTree;
			bTree->right->data = data;
			bTree->right->right = NULL;
			bTree->right->left = NULL;
		}
	}

}


void binTreeManager::print(binTree* bTree) {
    if (bTree->left != NULL) {
        cout << "LEFT BRANCH: " << bTree->left->data << endl;
        this->print(bTree->left);
    }
    cout << "BRACH: " << bTree->data << endl;
    if (bTree->right != NULL) {
        cout << "RIGHT BRANCH: " << bTree->right->data << endl;
        this->print(bTree->right);
    }




}



void binTreeManager::inOrder(binTree* bTree) {
    if (bTree == NULL) {
        return;
    }

    this->inOrder(bTree->left);

    cout << bTree->data << " ";

    this->inOrder(bTree->right);

}

void binTreeManager::preOrder(binTree* bTree) {
    if (bTree == NULL) {
        return;
    }

    cout << bTree->data << " ";

    this->preOrder(bTree->left);
    this->preOrder(bTree->right);

}

void binTreeManager::postOrder(binTree* bTree) {
    if (bTree == NULL) {
        return;
    }

    this->postOrder(bTree->left);
    this->postOrder(bTree->right);

    cout << bTree->data << " ";

}

void binTreeManager::autoBalance(binTree* bTree) {

    int left_count = 0;
    int right_count = 0;

    if(bTree == NULL) {
        return;
    }



    //RIGHT COUNT CHECK
    this->rightCounter(&right_count, bTree->right);
    //LEFT COUNT CHECK
    this->leftCounter(&left_count, bTree->left);

    int arr_size = left_count+right_count+1;

    int arr [arr_size];
    int index = 0;

    //this->fillInOrder(bTree, arr[], 0)
    this->fillInOrder(bTree, arr, index);
    cout << endl;
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << endl;
    }

    binTree *balancedTree = new binTree;
    int mid_el_index = arr_size/2 - 1;
    int mid_el = arr[mid_el_index];
    balancedTree->left = NULL;
    balancedTree->right = NULL;
    balancedTree->data = mid_el;

    for (int i = 0; i < arr_size; i++) {
        if (i == mid_el_index) {
            continue;
        }
        this->addData(arr[i], balancedTree);
    }

    cout << "IN_ORDER" << endl;
    this->inOrder(balancedTree);
    cout << " BALANCED TREE" << endl;
    this->inOrder(this->tree);
    cout << " THIS->TREE" << endl;

    cout << "PRE_ORDER" << endl;
    this->preOrder(balancedTree);
    cout << "BALANCED TREE" << endl;
    this->preOrder(this->tree);
    cout << "THIS->TREE" << endl;

    cout << "POST_ORDER" << endl;
    this->postOrder(balancedTree);
    cout << "BALANCED TREE" << endl;
    this->postOrder(this->tree);
    cout << "THIS->TREE" << endl;

//
//    cout << "LEFT DATA COUNT: " << left_count  << endl << "RIGHT DATA COUNT: " << right_count << endl;
//
//    if (left_count > right_count+1) {
//
//    }
//    if (right_count > left_count+1) {
//
//    }
}

void binTreeManager::fillInOrder(binTree * bTree, int arr[], int& index) {
if (bTree == NULL) {
        return;
    }

    if (bTree->left != NULL) {
        fillInOrder(bTree->left, arr, index);
    }

    arr[index] = bTree->data;

    index++;

    if (bTree->right != NULL) {
        fillInOrder(bTree->right, arr, index);
    }

}

void binTreeManager::leftCounter(int * left, binTree * bTree) {
    if (bTree != NULL) {
        ++*left;
        this->leftCounter(left, bTree->left);
        this->leftCounter(left, bTree->right);
    } else {
        return;
    }

}

void binTreeManager::rightCounter(int * right, binTree * bTree) {

    if (bTree != NULL) {
        ++*right;
        this->rightCounter(right, bTree->right);
        this->rightCounter(right, bTree->left);
    } else {
        return;
    }

}


