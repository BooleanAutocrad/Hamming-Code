#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;


vector<int> sendMessage(vector<int> &m,int r)
{
    
    reverse(m.begin(), m.end());

    for(int i=0;i<r;i++)
    {
        int a=pow(2,i);
        std::vector<int>::iterator it;

        it = m.begin();
        m.insert(it+a-1,2);
    }



    int d=0;
    //traversing the whole message
    for(int j=0;j<m.size();j++)
    {
        int count1=0;
        //checking for the redundent bit
        if(m[j]==2 && d<r)
        {
            //finding the redundent bit
            for(int i=j;i<m.size();i=i+(2*(j+1))) 
            {
                //finding the redundent pair
                for(int k=i;k<i+(pow(2,d));k++)  
                {
                    if(m[k]==1)
                    {
                        //finding the even parity
                        count1++;
                    }
                }
            }

            if(count1 % 2 == 0)
            {
                m[j]=0;
            }
            else
            {
                m[j]=1;
            }
            d++;
        }
    }
    
    reverse(m.begin(), m.end());

    //printing
    std::cout<<endl<<endl;
    std::cout<<"FINAL CODE TO BE SENT"<<endl;
    for(int i=0;i<m.size();i++)
    {
        std::cout<<m[i];
    }

    return m;

}

void correctError(vector<int> &em,int ep)
{
    if(em[ep]==1)
    {
        em[ep]=0;
    }
    else
    {
        em[ep]=1;
    }

    //printing
    std::cout<<endl<<endl;
    std::cout<<"THE CORRECTED MESSAGE IS :-"<<endl;
    for(int i=0;i<em.size();i++)
    {
        std::cout<<em[i];
    }
    
}

void checkMessage(vector<int> &m,int r)
{
    int errorPos=0,d=0;
    vector<int> originalMessage=m;
    vector<int> errorLoc;

    reverse(m.begin(), m.end());

    
    //traversing the whole message
    for(int j=0;j<m.size();j++)
    {
        int count1=0;
        //checking for the redundent bit
        while(j==(pow(2,d)-1) && d<r)
        {
            //finding the redundent bit
            for(int i=j;i<m.size();i=i+(2*(j+1))) 
            {
                //finding the redundent pair
                for(int k=i;k<i+(pow(2,d));k++)  
                {
                    if(m[k]==1)
                    {
                        //finding the even parity
                        count1++;
                    }
                }
            }

            if(count1 % 2 == 0)
            {
                errorLoc.push_back(0);
            }
            else
            {
                errorLoc.push_back(1);
            }
            d++;
        }
    }
    
    //errorLoc.reverse();

    for(int i=0;i<errorLoc.size();i++)
    {
        errorPos=errorPos+(errorLoc[i]*(pow(2,i)));
    }

    if(errorPos==0)
    {
        std::cout<<"\nNO ERROR HAS OCCURED . MESSAGE RECEIVED!!!\n"+errorPos;
    }
    else
    {
        std::cout<<"\n ERROR HAS OCCURED AT INDEX "<<errorPos-1<<endl;
        reverse(m.begin(), m.end());
        correctError(m,errorPos-1);
    }
}





int main()
{
    vector<int> m;//original message
    vector<int> sm;//hamming code
    vector<int> rm;//received message
    int d,e,f,r=0;


    std::cout<<"ENTER THE SIZE OF YOUR MESSAGE"<<endl;
    std::cin>>d;


    while(d+r+1> pow(2,r))
    {
        r++;
    }

    std::cout<<"NUMBER OF REDUNDENT BITS = "<<r<<endl<<endl;
  

    for(int i=0;i<d;i++)
    {
        std::cout<<"ENTER YOUR MESSAGE BIT BY BIT";
        std::cin>>e;
        m.push_back(e);
    }

    sm=sendMessage(m,r);

    std::cout<<endl<<endl;

    for(int i=0;i<(d+r);i++)
    {
        std::cout<<"ENTER YOUR RECEIVED MESSAGE BIT BY BIT";
        std::cin>>f;
        rm.push_back(f);
    }

    checkMessage(rm,r);
}