#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class node
{
    public:
        int data;
        vector<node *> child;
        bool visited;
        node() {}
        node(int d)
        {
            data = d;
            visited = false;
        }
};

class graph
{
    public:
        vector<node *> list;

        void unvisited()
        {
            for(int i=0; i < list.size(); i++)
            {
                list[i]->visited = false;
            }
        }

        void insert(node *u, node *v)
        {
            list.push_back(u);
            list.push_back(v);
            u->child.push_back(v);
            v->child.push_back(u);
        }

        void BFS(node *root)
        {
            queue<node *> q;
            q.push(root);
            root->visited = true;
            while(!q.empty())
            {
                int numberOfChildNodes = q.front()->child.size();
                for(int i=0; i<numberOfChildNodes; i++)
                {
                    if(q.front()->child[i]->visited == false)
                    {
                        q.push(q.front()->child[i]);
                        q.front()->child[i]->visited = true;
                    }
                }
                cout << q.front()->data << endl;
                q.pop();
            }

            cout << "isolated nodes" << endl;
            for(int i=0; i<list.size(); i++)
            {
                if(list[i]->visited == false)
                {
                    cout << list[i]->data << endl;
                    list[i]->visited = true;
                }
            }
            unvisited();
        }

        void DFS(node *root)
        {
            stack<node *> s;
            s.push(root);
            root->visited = true;
            while(!s.empty())
            {
                int i = s.top()->child.size();
                node *tem = s.top();
                cout << s.top()->data << endl;
                s.pop();
                for(int j=0; j < i; j++)
                {
                    if(tem->child[j]->visited == false)
                    {
                        s.push(tem->child[j]);
                        tem->child[j]->visited = true;
                    }
                }
            }

            cout << "isolated nodes" << endl;
            for(int i=0; i<list.size(); i++)
            {
                if(list[i]->visited == false)
                {
                    cout << list[i]->data << endl;
                    list[i]->visited = true;
                }
            }
            unvisited();
        }
};

int main()
{
    graph g; int i=-1, j;

    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);
    node *n6 = new node(6);
    node *n7 = new node(7);
    node *n8 = new node(8);

    g.insert(n1, n2);
    g.insert(n2, n3);
    g.insert(n1, n3);
    g.insert(n4, n3);
    g.insert(n5, n1);
    g.insert(n6, n2);
    g.insert(n4, n6);
    g.insert(n3, n5);
    g.insert(n7, n8);

    while(i != 0)
    {
        cout << endl << "Choose (1 --> BFS or 2 --> DFS and 0 --> exit)    :    ";
        cin >> i;
        switch(i)
        {
            case 1:
                cout << "Choose node number (1, 2, 3, 4, 5, 6, 7 or 8) : ";
                cin >> j;
                cout << endl << "BFS with respect to node " << j << " is" << endl;
                switch(j)
                {
                    case 1:
                        g.BFS(n1);
                        break;
                    case 2:
                        g.BFS(n2);
                        break;
                    case 3:
                        g.BFS(n3);
                        break;
                    case 4:
                        g.BFS(n4);
                        break;
                    case 5:
                        g.BFS(n5);
                        break;
                    case 6:
                        g.BFS(n6);
                        break;
                    case 7:
                        g.BFS(n7);
                        break;
                    case 8:
                        g.BFS(n8);
                        break;
                    default:
                        cout << "Choose from given numbers : improper input" << endl;
                        break;
                }
                break;
            case 2:
                cout << "Choose node number (1, 2, 3, 4, 5, 6, 7 or 8) : ";
                cin >> j;
                cout << endl << "DFS with respect to node " << j << " is" << endl;
                switch(j)
                {
                    case 1:
                        g.DFS(n1);
                        break;
                    case 2:
                        g.DFS(n2);
                        break;
                    case 3:
                        g.DFS(n3);
                        break;
                    case 4:
                        g.DFS(n4);
                        break;
                    case 5:
                        g.DFS(n5);
                        break;
                    case 6:
                        g.DFS(n6);
                        break;
                    case 7:
                        g.DFS(n7);
                        break;
                    case 8:
                        g.DFS(n8);
                        break;
                    default:
                        cout << "Choose from given numbers : improper input" << endl;
                        break;
                }
                break;
            case 0:
                cout << "successfully exited" << endl;
                break;
            default:
                cout << "OOPS!! try again : improper input" << endl;
                break;
        }
    }
    return 0;
}