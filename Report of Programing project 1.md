# Report of Programing project 1



This project is uploaded to github. 

https://github.com/tqhtqhtqhgo/Qtree

I use cmake to control the compile of the project.

Compile and test in terminal

```shell
cmake .
make
```

The project's header file and source file structure:

```mermaid
graph LR
A(treeStructure.h) -->B(buildTree.h)
    B --> C(writeTree.h)
    B --> Q(buildTree.c)
    C --> D(nodeValue.h) 
    C --> w(writeTree.c) 
    D --> H{main.c}
    D --> r(nodev\Value.c)

    F[Project structure]
```



## Task 1

The function destoryTree() is wrote in the writeTree.c and call the function in writeTree().

 Algorithm:

I use the  recursion, so if a node is not empty the program need to destory children by recursion.

```mermaid
graph LR
A[Node]-->B{Node is empty}
    B -->|Yes| D[Pass]
    B -->|No| E[Destory children and free node]
    E-->A
```

The function destoryTree() is :

```c
void destroyTree(Node *head){
    if(head!=NULL){
        destroyTree(head->child[0]);
        destroyTree(head->child[1]);
        destroyTree(head->child[2]);
        destroyTree(head->child[3]);
        free(head);
    }
}
```

And I call it in function writeTree() like:

```c
void writeTree( Node *head ) {
    FILE *fp = fopen("quad.out","w");
    writeNode(fp,head);
    fclose(fp);
    destroyTree(head);
}
```

After testing use valgrind and sanitizers, the function don't have memory problem.

Sanitizer is a memory analysis tool in gdb and lldb. if want to use it need to add flag in compile.

Because sanitizer and valgrind can't use at the same time, if you want to use valgrind, need to delete this line in CmakeList.txt .

```cmake
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
```

Valgrind:

![Screenshot_20200315_091131](/home/caaffrey/图片/Screenshot_20200315_091131.png)

Sanitizer:

![Screenshot_20200315_092454](/home/caaffrey/图片/Screenshot_20200315_092454.png)

After debugging, the function free all memory and don't have memory warning.

![Screenshot_20200315_092841](/home/caaffrey/图片/Screenshot_20200315_092841.png)

And use the proflier to analysis the time of how much cpu are used ,we can see call destoryTree() one time, it takes 14.29% off all time.



## Task 2

Because assume that all children are leaf nodes.

Do not need to use recursion.

 Algorithm just need to free the child node and make the pointer to children equal to NULL.

So the function is 

```c
void removeChild(Node *root){
    for (int i = 0; i <4 ; ++i) {
        free(root->child[i]);
        root->child[i]=NULL;
    }
}
```

 Test in main.c:

```c
    makeChildren(head->child[1]->child[1]);
    removeChild(head->child[1]->child[1]);
```

By test, the program don't have memory warning or error

Valgrind:

![Screenshot_20200315_091131](/home/caaffrey/图片/Screenshot_20200315_091131.png)

Sanitizer:

![Screenshot_20200315_092454](/home/caaffrey/图片/Screenshot_20200315_092454.png)

 All memory has been freed.

Gnuplot:

makeChildren

![Screenshot_20200315_103702](/home/caaffrey/图片/Screenshot_20200315_103702.png)

removeChild

![Screenshot_20200315_103617](/home/caaffrey/图片/Screenshot_20200315_103617.png)

## Task 3

By the function given by nodeValue.c.

The  algorithm is:

if a node's nodeValue is larger than 0.5 and is leaf node then makechildren for it, else if it isn't a leaf ode and all 4 children's value  less than -0.5 then remove it.

Adapt is based on this and loop.

```mermaid
graph LR
A[Node]-->B{NodeValue}
    B -->|-0.5-0.5| D[Pass]
    B -->|0.5-1 and is leaf node| E[makeChildren]
    B -->|-1-0.5 and is not leaf node|F[removeChildren]
    E --> |adapt and loop Max level ==6|A
    F --> |adapt and loop Max level ==6|A
```

Valgrind:

![Screenshot_20200315_102923](/home/caaffrey/图片/Screenshot_20200315_102923.png)

Result of Gnuplot:

Task3( function generateTree() ):

![Screenshot_20200315_103350](/home/caaffrey/图片/Screenshot_20200315_103350.png)

Adapt:

![Screenshot_20200315_103300](/home/caaffrey/图片/Screenshot_20200315_103300.png)

## Reflection

I thought the hardest part is the  code of  task3 because of the logic is complex than task 1 and 2, and some time need to consider the time complexity. and In the process , I write some code can't run out result use long time.  

