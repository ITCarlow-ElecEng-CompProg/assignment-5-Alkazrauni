/** Salman Al-kazrauni
 *  c00199530
 *  Exercise 5
 *  Method of Least Squares of Linear Regression1 */


#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    /**< variables for sums/sigma of xi,yi,xi^2,xiyi etc */
    double xsum = 0 , x2sum = 0 , ysum = 0 , xysum = 0, y_fit[100];
    /**< initialize the y and x arrays */
    double  x[100] , y[100] , m , c ;
    int i , n ;

    /**< Prompt the user to enter the number of data points */
    do
    {
        cout << "Enter the no. of data pairs to be entered: ";
        cin >> n;
    }
    while ((n <= 0) || (n > 100));

    /**< asking for the x values */
    cout << "\nEnter the x-axis values:\n";

    for ( i = 0 ; i < n ; i++ )
    {
        cin >> x[i] ;
    }

    /**< asking for the y values */
    cout << "\nEnter the y-axis values:\n";

    for ( i = 0 ; i < n ; i++ )
    {
        cin >> y[i];
    }

    for ( i = 0 ; i < n ; i++ )
    {
        /**< calculate the sigma ( xi, yi, x^2i and xi*yi ) */
        xsum = xsum + x[i];
        ysum = ysum + y[i];
        x2sum = x2sum + pow(x[i],2);
        xysum = xysum + x[i] * y[i];
    }

    /**< calculate the slope and the intercept */
    m = ( n * xysum - xsum * ysum ) / ( n * x2sum - xsum * xsum );
    c = ( ysum / n ) - m * ( xsum / n );

    /**< to calculate y(fitted) at given x points */
    for ( i = 0 ; i < n ; i++ )
    {
        y_fit[i] = m * x[i] + c;
    }

    cout << "\nS.no" << setw(6) << "x" << setw(19) << "y(observed)" <<setw(19) << "y(fitted)" <<endl;
    cout << "--------------------------------------------------------\n";

    /**< display the table for the x values, y values and the y fitted values */
    for ( i = 0 ; i < n ; i++ )
    {
        cout << i + 1 << "." << setw(8) << x[i] << setw(15) << y[i] << setw(18) << y_fit[i] << endl;
    }

    /**< display the equation for this straight line */
    cout << "\nThe equation for the straight line is:\n\n"<< "    y = " << m << "x + " << c << endl;

    return 0;
}
