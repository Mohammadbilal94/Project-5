#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class URLs
{
public:
        string scheme, authority, path;
        URLs(string scheme, string authority, string path)
        {
                this->scheme = scheme;
                this -> authority = authority;
                this -> path = path;
        }
        string getScheme()
        {
                return this->scheme;
        }

        string getAuthority()
        {
                return this->authority;
        }

        string getPath()
        {
                return this->path;
        }
        string getUrl()
        {
                return scheme + "." + authority + "." + path;
        }
};

int main()
{
    string url,scheme,authority,path;

    int pos,p,pos2,m;

    cout<<"ENTER WEBSITE URL : "; 
    cin>>url;
    pos2 = url.find(":");        

   
    for (int i=0;i<url.size();i++)
    {
        if(url[i]=='/' && url[i+1]=='/')
        {
            pos = i;
            i++;
        }
        else if(url[i]=='/' && url[i+1]!='/')
        {
            p=i;
            break;
        }
    }

    scheme= url.substr(0,pos2+1);      

    m=((url.size()-pos2)-(url.size()-p))-1;
    authority = url.substr(pos,m);     

    path = url.substr(p);              

    cout<<endl;
    cout<<"Scheme : "<<scheme<<endl;
    cout<<"Authority : "<<authority<<endl;
    cout<<"Path : "<<path<<endl;
    return 0;
}

