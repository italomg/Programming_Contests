#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
    string containers;
    int testn = 0;
    while(cin>>containers)
    {
        if(containers == "end") break;
 
        int len = containers.size();
	int containerStack[10010];

        for(int i = 0; i < len; i++)
        {
            containerStack[i]=1;
            for(int j=0;j<i;j++)
            {
                if(containers[j]%'A' < containers[i]%'A')
                    containerStack[i]=max(containerStack[i],1+containerStack[j]);
            }
        }

        int nstack=0;
        for(int i = 0; i < len; i++)
	  nstack=max(nstack,containerStack[i]);

	testn++;
	printf("Case %d:", testn);
	printf(" %d\n",nstack);
    }
    return 0;
}
