template <typename T1, typename T2>

class Pair{
    T1 x;
    T2 y;  

    public:
    void setX(T1 x){
        this->x = x;
    }
    void setY(T2 y){
        this->y = y;
    }
    T1 getX(){
        return x;
    }
    T2 getY(){
        return y;
    }
};