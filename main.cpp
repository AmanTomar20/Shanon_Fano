#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Fano
{
    char sym;
    double p;
    string c;
}F[20];
void shanon(int,int);

void shanon(int h,int t)
{
    if(h>=t-1)
        return;
    int k=1,i;
    double diff1,diff2,pk1=0,pk2=0;
    pk1=F[h].p;
    for(i=k;i<t;i++)
        pk2=pk2+F[i].p;
    diff1=pk2-pk1;
    if(diff1<0)
        diff1=-diff1;
    while(1)
    {
        k++;
        pk1=pk2=0;
        for(i=h;i<k;i++)
            pk1=pk1+F[i].p;
        for(i=k;i<t;i++)
            pk2=pk2+F[i].p;
        diff2=pk2-pk1;
        if(diff2<0)
            diff2=-diff2;
        if(diff1>diff2)
        {
            diff1=diff2;
            continue;
        }
        else
        {
            for(i=h;i<k-1;i++)
                F[i].c.append("1");
            for(i=k-1;i<t;i++)
                F[i].c.append("0");
            break;
        }
    }
    shanon(h,k-1);
    shanon(k-1,t);
}

void Display(int n)
{
    cout<<"\n\nSymbol  "<<"Probability  "<<"codeword"<<endl;
    for(int i=0;i<n;i++)
        cout<<F[i].sym<<"\t"<<F[i].p<<"\t\t"<<F[i].c<<endl;
}

bool compare(Fano A,Fano B)
{
    if(A.p!=B.p)
        return A.p>B.p;
    else
    return false;
}
int main()
{
    int n,j;
    double sum;
    cout<<"Enter the no. of symbols: ";
    cin>>n;
    cout<<endl;
    do{
            sum=0;
            for(char i='A';i<('A'+n);i++)
            {
                cout<<"Enter Probability of "<<i<<": ";
                cin>>F[int(i-'A')].p;
                F[int(i-'A')].sym=i;
            }
            for(j=0;j<n;j++)
                sum=sum+F[j].p;
            if(sum!=1)
                cout<<"\nThe entered probabilities are not correct.\n\nEnter again:\n";

    }while(sum!=1);
    sort(F,F+n,compare);

    shanon(0,n);

    Display(n);
    return 0;
}


