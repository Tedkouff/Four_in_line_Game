#include <iostream>

using namespace std;

bool isValidTable(int n, int m)
{
    if(n>=4 && m>=4 && n<=20 && m<=40) return true;
    else return false;
}

char insertXO(int n)
{
    if(n%2==0) return 'X';
    else return 'O';
}

bool isFullTable(int h, int w, char table[20][81])
{

    for(int i=0;i<h;i++)
    {
        for(int j=1;j<w*2+1;j+=2)
        {
            if(table[i][j]==' ') return false;
        }
    }
    return true;
}

bool isFullColumn(int column, char table[20][81])
{
    if(table[0][2*column-1]!=' ') return true;
    else return false;
}

bool player1Wins(int h, int w, char table[20][81])
{
    for(int j=1;j<w*2+1;j+=2)
    {

        for(int i=0;i<h-3;i++)
        {
            if(table[i][j]=='O' && table[i+1][j]=='O' && table[i+2][j]=='O' && table[i+3][j]=='O')
            {
                return true;
            }
        }
    }

    for(int i=0;i<h;i++)
    {
        for(int j=1;j<w*2-5;j+=2)
        {
            if(table[i][j]=='O' && table[i][j+2]=='O' && table[i][j+4]=='O' && table[i][j+6]=='O')
            {
                return true;
            }
        }
    }

    for(int j=1;j<w*2-5;j+=2)
    {

        for(int i=0;i<h-3;i++)
        {
            if(table[i][j]=='O' && table[i+1][j+2]=='O' && table[i+2][j+4]=='O' && table[i+3][j+6]=='O')
            {
                return true;
            }
        }
    }


    for(int j=2*w-1;j>6;j-=2)
    {

        for(int i=0;i<h-3;i++)
        {
            if(table[i][j]=='O' && table[i+1][j-2]=='O' && table[i+2][j-4]=='O' && table[i+3][j-6]=='O')
            {
                return true;
            }
        }
    }

    return false;
}

bool player2Wins(int h, int w, char table[20][81])
{
    for(int j=1;j<w*2+1;j+=2)
    {

        for(int i=0;i<h-3;i++)
        {
            if(table[i][j]=='X' && table[i+1][j]=='X' && table[i+2][j]=='X' && table[i+3][j]=='X')
            {
                return true;
            }
        }
    }

    for(int i=0;i<h;i++)
    {
        for(int j=1;j<w*2-5;j+=2)
        {
            if(table[i][j]=='X' && table[i][j+2]=='X' && table[i][j+4]=='X' && table[i][j+6]=='X')
            {
                return true;
            }
        }
    }

    for(int j=1;j<w*2-5;j+=2)
    {

        for(int i=0;i<h-3;i++)
        {
            if(table[i][j]=='X' && table[i+1][j+2]=='X' && table[i+2][j+4]=='X' && table[i+3][j+6]=='X')
            {
                return true;
            }
        }
    }

    for(int j=2*w-1;j>6;j-=2)
    {

        for(int i=0;i<h-3;i++)
        {
            if(table[i][j]=='X' && table[i+1][j-2]=='X' && table[i+2][j-4]=='X' && table[i+3][j-6]=='X')
            {
                return true;
            }
        }
    }

    return false;
}

void startGame(int height, int width )
{
    char table[20][81];

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<2*width+1;j++)
        {
            if(j%2==0) table[i][j]='|';
            else table[i][j]=' ';
        }
    }

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<2*width+1;j++)
        {
            cout<<table[i][j];
        }cout<<endl;
    }
    int position;
    int counter=1;

    do{
        if(isFullTable(height,width,table)==1)
        {
            cout<<"There is no winner!";
            break;
        }
        cin>>position;
        cout<<endl;

        if(!(position>0 && position<=width ))
        {
            cout<<"Invalid column! Select valid column!"<<endl;
            continue;
        }

        if(isFullColumn(position,table))
        {
            cout<<"This column is full! Select another one!"<<endl;
            continue;
        }

        if (position>1)
            position=position*2-1;

        for(int i=height-1;i>=0;i--)
        {
            if(table[i][position]==' ')
            {
                table[i][position]=insertXO(counter);
                counter++;
                break;
            }

        }

        for(int i=0;i<height;i++)
        {
            for(int j=0;j<2*width+1;j++)
            {
                cout<<table[i][j];
            }cout<<endl;
        }

        if(player1Wins(height,width,table))
        {
            cout<<endl<<"Player1 wins!";
            break;
        }

        if(player2Wins(height,width,table))
        {
            cout<<endl<<"Player2 wins!";
            break;
        }

    }
    while(true);

}


int main() {

    int height , width;
    cin>>height>>width;
    if(!isValidTable(height,width))
    {
        cout<<"Invalid values of table!";
        return -1;
    }

    startGame(height,width);


    return 0;
}
