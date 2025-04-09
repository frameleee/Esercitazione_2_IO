#include <iostream>
#include <iomanip>
#include "Eigen/Eigen"


using namespace std;
using namespace Eigen;

// ERRORE RELATIVO
double err_rel(const Vector2d& x) {
	Vector2d xa(-1.0, -1.0);
	double err_ass = (x - xa).norm();
	double err_rel = err_ass / (xa.norm());
	return err_rel;
	
}

int main()
{
	cout << setprecision(15) << scientific << endl;
	// sistema 1
	Matrix2d A1 {
		{5.547001962252291e-01, -3.770900990025203e-02},
		{8.320502943378437e-01, -9.992887623566787e-01},
	};
	Vector2d b1 {
		{-5.169911863249772e-01, 1.672384680188350e-01}
	};
	
	FullPivLU<Matrix2d> lu1(A1);
	Vector2d x1_LU = lu1.solve(b1);
	
	
	HouseholderQR<Matrix2d> qr1(A1);
	Vector2d x1_QR = qr1.solve(b1);
	
	cout << "x1_LU = [" << x1_LU << "] \n" << endl;
	cout << "x1_QR = [" << x1_QR << "] \n" << endl;
	cout << "Errore relativo del sistema 1 con PALU: " << err_rel(x1_LU) << endl;
	cout << "Errore relativo del sistema 1 con QR: " << err_rel(x1_QR) << "\n" << endl;
	
	cout << "--------------------------------- \n" << endl;
	
	// sistema 2
	Matrix2d A2 {
		{5.547001962252291e-01, -5.540607316466765e-01},
		{8.320502943378437e-01, -8.324762492991313e-01},
	};
	Vector2d b2 {
		{-6.394645785530173e-04, 4.259549612877223e-04}
	};
	
	FullPivLU<Matrix2d> lu2(A2);
	Vector2d x2_LU = lu2.solve(b2);
	
	HouseholderQR<Matrix2d> qr2(A2);
	Vector2d x2_QR = qr2.solve(b2);
	
	cout << "x2_LU = [" << x2_LU << "] \n" << endl;
	cout << "x2_QR = [" << x2_QR << "] \n" << endl;
	cout << "Errore relativo del sistema 2 con PALU: " << err_rel(x2_LU) << endl;
	cout << "Errore relativo del sistema 2 con QR: " << err_rel(x2_QR) << "\n" << endl;
	
	cout << "--------------------------------- \n" << endl;
	
	// sistema 3
	Matrix2d A3 {
		{5.547001962252291e-01, -5.547001955851905e-01},
		{8.320502943378437e-01, -8.320502947645361e-01},
	};
	Vector2d b3 {
		{-6.400391328043042e-10, 4.266924591433963e-10}
	};
	
	FullPivLU<Matrix2d> lu3(A3);
	Vector2d x3_LU = lu3.solve(b3);
	
	HouseholderQR<Matrix2d> qr3(A3);
	Vector2d x3_QR = qr3.solve(b3);
	
	cout << "x3_LU = [" << x3_LU << "] \n" << endl;
	cout << "x3_QR = [" << x3_QR << "] \n" << endl;
	cout << "Errore relativo del sistema 3 con PALU: " << err_rel(x3_LU) << endl;
	cout << "Errore relativo del sistema 3 con QR: " << err_rel(x3_QR) << endl;
	
    return 0;
}