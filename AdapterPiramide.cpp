//Lopez Chavez Pablo
#include<iostream>
#include<math.h>
using namespace std;
class RoundPeg{
    public:
    double Radius;
    RoundPeg();
    RoundPeg(double rad){
        Radius=rad;
    }
    double getRadius(){
        return Radius; 
    }
};
class RoundHole {
    private:
        double radius;
    public:
        RoundHole(double radius) {
            this->radius = radius;
        }
        double getRadius() {
            return radius;
        }
        bool fits(RoundPeg* peg) {
            return getRadius() >= peg->getRadius();
        }
};
class PyramidPeg {
    public:
    double area;
    int lados;
    PyramidPeg();
    PyramidPeg(double area,int lados){
        this->area=area;
        this->lados=lados;
    }
    double getArea(){
        return area;
    }
    int getLados(){
        return 3*lados;
    }

};
class PyramidPegAdapter :public RoundPeg{
    private:
    PyramidPeg * peg;
    public:
        PyramidPegAdapter(PyramidPeg* peg) : RoundPeg(peg->getLados()/ (4 *peg->getArea())){}
};
int main(){
    //Se quiere crear un hoyo de radio 3 unidades
    RoundHole* hole = new RoundHole(3);
    RoundPeg* rpeg = new RoundPeg(3);
    if (hole->fits(rpeg)) {
        cout << "La clavija encaja en el agujero." <<endl;
    } else {
        cout << "La clavija no encaja en el agujero." <<endl;
    }
    PyramidPeg* small_sqpeg = new PyramidPeg(8,2);
    PyramidPeg* large_sqpeg = new PyramidPeg(5,20);
    //Se crea un adaptador que convierte una clavija ya sea de cualquier forma a un hoyo circular

    //Se crea una clavija pequeña que no entra

    //Se crea una clavija grande que cumple con los requisitos que el radi salga 3
    
    PyramidPegAdapter* small_sqpeg_adapter = new PyramidPegAdapter(small_sqpeg);
    
    if (hole->fits(small_sqpeg_adapter)) {
        cout << "La clavija En forma de Piramide pequeña encaja en el agujero." <<endl;
    } else {
        cout << "La clavija En forma de Piramide pequeña no encaja en el agujero." <<endl;
    }

    PyramidPegAdapter* large_sqpeg_adapter = new PyramidPegAdapter(large_sqpeg);
    
    if (hole->fits(large_sqpeg_adapter)) {
        cout << "La clavija En forma de Piramide grande encaja en el agujero." <<endl;
    } else {
        cout << "La clavija En forma de Piramide grande no encaja en el agujero." <<endl;
    }

    return 0;
}