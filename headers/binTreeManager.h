#ifndef BINTREEMANAGER_H_INCLUDED
#define BINTREEMANAGER_H_INCLUDED

#include "binTree.h"

class binTreeManager {

    private:
        binTree * tree = NULL;
    public :
        binTreeManager();
        ~binTreeManager();

        void addData(int);
        void addData(int, binTree*);

        void print(binTree*);

        void inOrder(binTree*);
        void preOrder(binTree*);
        void postOrder(binTree*);
        void autoBalance(binTree*);

        void leftCounter(int *, binTree *);
        void rightCounter(int *, binTree *);

        void fillInOrder(binTree *,int arr[],int &);

};

#endif // BINTREEMANAGER_H_INCLUDED
