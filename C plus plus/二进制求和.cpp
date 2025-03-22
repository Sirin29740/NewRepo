class Solution {
public:
    string addBinary(string a, string b) {
        int al=a.size();
        int bl=b.size();
        while(al<bl)
        {
            a='0'+a;
            al++;
        }
        while(bl<al)
        {
            b='0'+b;
            bl++;
        }
        for(int i=al-1;i>0;i--)
        {
            if(a[i]=='2'){a[i]='0';a[i-1]=a[i-1]+1;}
            if(a[i]-'0'+b[i]=='2'){a[i]='0';a[i-1]=a[i-1]+1;}
            else a[i]=a[i]-'0'+b[i];
        }
        if(a[0]-'0'+b[0]=='2'){a[0]='0';a='1'+a;}
        else if(a[0]-'0'+b[0]=='3'){a[0]='1';a='1'+a;}
        else a[0]=a[0]-'0'+b[0];
        return a;
    }
};
