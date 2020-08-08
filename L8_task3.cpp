#include <iostream>

using namespace std;

class IllegalCommand{
    private:
        int x;
        int y;
        int posX;
        int posY;
    public:
        IllegalCommand(int _x, int _y, int _posX, int _posY ) : x(_x), y(_y), posX(_posX), posY(_posY)  {}
        friend ostream& operator<<(ostream& out, IllegalCommand& i){
            out << "Robot is in position: x = " << i.posX << ", y = " << i.posY << endl;
            out << "Robot can make only one square move!" << endl;
            return out;
        }
};
class OffTheField{
private:
        int x;
        int y;
        int posX;
        int posY;
public:
    OffTheField(int _x, int _y, int _posX, int _posY ) : x(_x), y(_y), posX(_posX), posY(_posY) {}
    friend ostream& operator<<(ostream& out, OffTheField& o){
        out << "Robot is in position: x = " << o.posX << ", y = " << o.posY << endl;
        out << "Command is out of range 10x10!" << endl;
        return out;
    }
};

class Robot{
private:
    int posX;
    int posY;
public:
    Robot() {
        posX = 1;
        posY = 1;
    }
    void move(int moveX, int moveY){
        if (moveX > 1 || moveX < -1 || moveY > 1 || moveY < -1){
            throw IllegalCommand(posX, posY, moveX, moveY);
        } else if  ((posX == 1 && moveX == -1)|| (posX == 10 && moveX == 1) || (posY == 1 && moveY == -1) || (posY == 10 && moveY == 1)) {
            throw OffTheField(posX, posY, moveX, moveY);            
        }
        posX += moveX;
        posY += moveY;
        cout << "Robot at position " << posX << ", " << posY << endl;
    }
};


int main(){
    
    int X = 0;
    int Y = 0;
    Robot r;
    cout << "Robot starts at position 1, 1" << endl;
    cout << "Enter X (11 to exit): " << endl;
    cin >> X;
    if (X != 11){
        cout << "Enter Y: " << endl;
        cin >> Y;
    }
    while(X != 11){
        try{
            r.move(X, Y);
        }
        catch(IllegalCommand& i){
            cerr << i << endl;
        }
        catch(OffTheField& o){
            cerr << o << endl;
        }
        cout << "Enter X (11 to exit): " << endl;
        cin >> X;
        if (X != 11){
            cout << "Enter Y: " << endl;
            cin >> moveY;
        }
    }
    return 0;
}
