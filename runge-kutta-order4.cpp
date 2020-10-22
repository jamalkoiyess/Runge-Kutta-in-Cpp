#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;

/*  Here we have the functions gotten from the PDE, with x y z w being the four variables.
    To change the functions, simply change what each returns. This should be deduced from the PDE. */
double f1(double x, double y, double z, double w){
    return z;
}

double f2(double x, double y, double z, double w){
    return w;
}

double f3(double x, double y, double z, double w){
    return (-x-2*x*y);
}

double f4(double x, double y, double z, double w){
    return (-y -pow(x,2) + pow(y,2));
}


// Main Execution
int main(){
    // Here we write the time settings, make dt smaller if you want accuracy, and T larger if you want more range.
    // Be careful however, since doing so will raise NT, which means more data and longer execution time.
    cout << "Initializing time variables ..." << endl;
    double dt = 0.01;
    double T = 1000;
    double NT = T/dt;
    int NN = (int)NT;
    cout << "Done." << endl;

    cout << "Initializing coordinates ..." << endl;
    // The c array is for the equations (usually written h in textbooks). Don't change it.
    double c[4][4];
    double x; double y; double z; double w;
    // Here you can set your initial conditions.
    x = -0.2215; y = 0.0469; z = 0.3397; w = -0.4025;
    cout << "Done." << endl;

    // Creating the data file
    std::ofstream myFile("Data.csv");
    cout << "Data File Opened." << endl;

    // The integration loop
    cout << "Integrating ... [0%]" << endl;
    for(int i=0; i<NN+1; i++){
        // DO NOT CHANGE THESE EUQATIONS.
        c[0][0] = dt*f1(x,y,z,w);
        c[1][0] = dt*f2(x,y,z,w);
        c[2][0] = dt*f3(x,y,z,w);
        c[3][0] = dt*f4(x,y,z,w);
    
        c[0][1] = dt*f1(x + 0.5*c[0][0],y + 0.5*c[1][0],z + 0.5*c[2][0],w + 0.5*c[3][0]);
        c[1][1] = dt*f2(x + 0.5*c[0][0],y + 0.5*c[1][0],z + 0.5*c[2][0],w + 0.5*c[3][0]);
        c[2][1] = dt*f3(x + 0.5*c[0][0],y + 0.5*c[1][0],z + 0.5*c[2][0],w + 0.5*c[3][0]);
        c[3][1] = dt*f4(x + 0.5*c[0][0],y + 0.5*c[1][0],z + 0.5*c[2][0],w + 0.5*c[3][0]);
    
        c[0][2] = dt*f1(x + 0.5*c[0][1],y + 0.5*c[1][1],z + 0.5*c[2][1],w + 0.5*c[3][1]);
        c[1][2] = dt*f2(x + 0.5*c[0][1],y + 0.5*c[1][1],z + 0.5*c[2][1],w + 0.5*c[3][1]);
        c[2][2] = dt*f3(x + 0.5*c[0][1],y + 0.5*c[1][1],z + 0.5*c[2][1],w + 0.5*c[3][1]);
        c[3][2] = dt*f4(x + 0.5*c[0][1],y + 0.5*c[1][1],z + 0.5*c[2][1],w + 0.5*c[3][1]);
    
        c[0][3] = dt*f1(x + c[0][2],y + c[1][2],z + c[2][2],w + c[3][2]);
        c[1][3] = dt*f2(x + c[0][2],y + c[1][2],z + c[2][2],w + c[3][2]);
        c[2][3] = dt*f3(x + c[0][2],y + c[1][2],z + c[2][2],w + c[3][2]);
        c[3][3] = dt*f4(x + c[0][2],y + c[1][2],z + c[2][2],w + c[3][2]);
    
        // Saving to the file
         myFile << x << " " << y << " " << z << " " << w << "\n";

        x = x +   (c[0][0] + 2*c[0][1] + 2*c[0][2] +c[0][3])/6;
        y = y +   (c[1][0] + 2*c[1][1] + 2*c[1][2] +c[1][3])/6;
        z = z + (c[2][0] + 2*c[2][1] + 2*c[2][2] +c[2][3])/6;
        w = w + (c[3][0] + 2*c[3][1] + 2*c[3][2] +c[3][3])/6;
        
        // This is a primitive progress bar
        if(i == NN/5){
            cout << "Integrating ... [20%]" << endl;
        }
        if(i == 2*NN/5){
            cout << "Integrating ... [40%]" << endl;
        }
        if(i == 3*NN/5){
            cout << "Integrating ... [60%]" << endl;
        }
        if(i == 4*NN/5){
            cout << "Integrating ... [80%]" << endl;
        }
        if(i == NN-1){
            cout << "Integrating ... [99%]" << endl;
        }
    }
    cout << "Done." << endl;
    
    myFile.close();
    return 0;
}
