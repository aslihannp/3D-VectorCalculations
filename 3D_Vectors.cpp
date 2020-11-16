#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

typedef struct {
	double x;
	double y;
	double z;
} Vector;

void print_vector(const Vector v);
Vector sum(const Vector v1, const Vector v2);
Vector diff(const Vector v1, const Vector v2);
double dot_product(const Vector v1, const Vector v2);
Vector cross_product(const Vector v1, const Vector v2);
double norm(const Vector v);
int is_unitvector(const Vector v);
Vector unit(const Vector v);
Vector multiplyby_scalar(const Vector v1, const double c);
double angle(const Vector v1, const Vector v2);
double distance(const Vector v1, const Vector v2);
int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3);
int are_orthogonal(const Vector v1, const Vector v2, const Vector v3);
int are_orthonormal(const Vector v1, const Vector v2, const Vector v3);
Vector projection(const Vector v1, const Vector v2);
Vector orthogonal_projection(const Vector v1, const Vector v2);
int convert_2_orthogonal_basis(Vector* v1, Vector* v2, Vector* v3);
char* vector2str(const Vector v);



int main()
{
	
	Vector v1, v2, v3;
	int a;
	double k;

	printf("Which operation do you need?\n");
	printf("1.Sum of vectors\n");
	printf("2.Difference of vectors\n");   
	printf("3.Multiply the vector by scalar\n");   
	printf("4.Dot product of vectors\n");   
	printf("5.Cross product of vectors\n");   
	printf("6.Norm of a vector\n"); 
	printf("7.Is vector unit?\n");  
	printf("8.Transform the vector to a unit vector\n");
	printf("9.The angle between two verctors\n");
	printf("10.Distance between two vectors\n");
	printf("11.Is 3 vector linearly independent?\n");
	printf("12.Is 3 vector orthogonal?\n");
	printf("13.Is 3 vector orthonormal?\n");
	printf("14.The projection v1 on v2\n");
	printf("15.The orthogonal projection v1 on v2\n");
	printf("16.Convert 3 linearly dependent vectors to linearly independent with Gram_Schmidt method\n");
	printf("17.string writing of vector\n");
	scanf("%d",&a);
	
	

	/*printf("v1 = ");
	print_vector(v1);
	printf("v2 = ");
	print_vector(v2);
	printf("v3 = ");
	print_vector(v3);*/

	switch (a){
	
	case 1:
		printf("Enter the vectors:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("v1 + v2 = ");
		print_vector(sum(v1, v2));
		break;
	case 2:
		printf("Enter the vectors:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("v1 - v2 = ");
		print_vector(diff(v1, v2));
		break;
	case 3:
		printf("Enter the vector:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("Enter the scalar:\nk=");
		scanf("%lf",&k);
		printf("k * v1  = ");
		print_vector(multiplyby_scalar(v1, k));
		break;
	case 4:
		printf("Enter the vectors:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("v1 . v2 = %.2lf\n", dot_product(v1, v2));
		break;
	case 5:
		printf("Enter the vectors:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("v1 x v2 = ");
		print_vector(cross_product(v1, v2));
		break;
	case 6:
		printf("Enter the vector:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("| v1 |  = %.2lf\n", norm(v1));
		break;
	case 7:
		printf("Enter the vector:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);		
		if (is_unitvector(v1))
			printf("v1 is a unit vector.\n");
		else
			printf("v1 is not unit vector.\n");
		break;
	case 8:
		printf("Enter the vector:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);	
		printf("unit( v1 ) = ");
		print_vector(unit(v1));
		break;
	case 9:
		printf("Enter the vectors:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("angle(v1, v2) = %.2lf\n", angle(v1, v2));
		break;
	case 10:
		printf("Enter the vectors:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
	    printf("distance(v1, v2) = %.2lf\n", distance(v1, v2));
	    break;
	    
	case 11:
		printf("Enter the vectors:\nV1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("V3=");
		scanf("%lf %lf %lf",&v3.x,&v3.y,&v3.z);
		if (are_linearly_independent(v1, v2, v3))
			printf("Vectors are linearly independent.\n");
		else
			printf("Vectors are not linearly independent.\n");
		break;
		
	case 12:
		printf("Enter the vectors:\n V1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("V3=");
		scanf("%lf %lf %lf",&v3.x,&v3.y,&v3.z);
		if (are_orthogonal(v1, v2, v3))
			printf("Vectors are orthogonal.\n");
		else
			printf("Vectors are not orthogonal.\n");
		break;
		
	case 13:
		printf("Enter the vectors:\n V1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("V3=");
		scanf("%lf %lf %lf",&v3.x,&v3.y,&v3.z);

		if (are_orthonormal(v1, v2, v3))
			printf("Vectors are orthonormal.\n");
		else
			printf("Vectors are not orthonormal.\n");
		break;
	case 14:
		printf("Enter the vectors:\n V1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("Projection of v1 onto v2 is = ");
		print_vector(projection(v1, v2));
		break;
	case 15:
		printf("Enter the vectors:\n V1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("Orthogonal projection of v1 onto v2 is = ");
		print_vector(orthogonal_projection(v1, v2));
		break;
		
	case 16:
		printf("Enter the vectors:\n V1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		printf("V2=");
		scanf("%lf %lf %lf",&v2.x,&v2.y,&v2.z);
		printf("V3=");
		scanf("%lf %lf %lf",&v3.x,&v3.y,&v3.z);

		if (convert_2_orthogonal_basis(&v1, &v2, &v3)) {
			printf("Orthogonalization of vectors:\n");
			printf("v1 = ");
			print_vector(v1);
			printf("v2 = ");
			print_vector(v2);
			printf("v3 = ");
			print_vector(v3);
		}
		break;
	case 17:
		printf("Enter the vector:\n V1=");
		scanf("%lf %lf %lf",&v1.x,&v1.y,&v1.z);
		puts(vector2str(v1));
		break;
}

	return 0;
}

void print_vector(const Vector v) {
	printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}

Vector sum(const Vector v1, const Vector v2) {
	Vector u1 = { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };

	return u1;
}

Vector diff(const Vector v1, const Vector v2) {
	Vector u1 = { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };

	return u1;
}

double dot_product(const Vector v1, const Vector v2) {

	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

Vector cross_product(const Vector v1, const Vector v2) {

	return { (v1.y * v2.z) - (v1.z * v2.y), (v1.z * v2.x) - (v1.x * v2.z), (v1.x * v2.y) - (v1.y * v2.x) };
}
double norm(const Vector v) {
	return pow(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2), 0.5);
}
int is_unitvector(const Vector v) {
	if (pow(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2), 0.5) == 1)
		return 1;
	else
		return 0;

}
Vector unit(const Vector v) {
	Vector u1 = { v.x, v.y, v.z };
	double norm = pow(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2), 0.5);
	u1 = { v.x / norm ,v.y / norm, v.z / norm };
	return u1;

}
Vector multiplyby_scalar(const Vector v1, const double c) {
	Vector u1 = { v1.x * c, v1.y * c, v1.z * c };

	return u1;

}
double angle(const Vector v1, const Vector v2) {
	double dotprod = dot_product(v1, v2);
	double norm1 = norm(v1);
	double norm2 = norm(v2);
	return acos(dotprod / (norm1 * norm2));
}
double distance(const Vector v1, const Vector v2) {
	Vector difference = diff(v1, v2);
	double distance = norm(difference);
	return distance;
}
int are_linearly_independent(const Vector v1, const Vector v2, const Vector v3) {
	//det(v1,v2,v3)=v1.(v2xv3)
	Vector cross = cross_product(v2, v3);
	double det = dot_product(v1, cross);

	if (det != 0)
		return 1;
	else
		return 0;

}
int are_orthogonal(const Vector v1, const Vector v2, const Vector v3) {
	double dotprod1 = dot_product(v1, v2);//v1.v2
	double dotprod2 = dot_product(v1, v3);//v1.v3
	double dotprod3 = dot_product(v2, v3);//v2.v3
	if (dotprod1 == 0 && dotprod2 == 0 && dotprod3 == 0)
		return 1;
	else
		return 0;

}
int are_orthonormal(const Vector v1, const Vector v2, const Vector v3) {
	double dotprod1 = dot_product(v1, v2);//v1.v2
	double dotprod2 = dot_product(v1, v3);//v1.v3
	double dotprod3 = dot_product(v2, v3);//v2.v3
	double norm1 = norm(v1);
	double norm2 = norm(v2);
	double norm3 = norm(v3);
	if (dotprod1 == 0 && dotprod2 == 0 && dotprod3 == 0 && norm1 == 1 && norm2 == 1 && norm3 == 1)
		return 1;
	else
		return 0;

}
Vector projection(const Vector v1, const Vector v2) {
	double dotprod = dot_product(v1, v2); //v1.v2
	double norm2 = pow(norm(v2), 2);  //|v2|^2
	double division = dotprod / norm2;  //(v1.v2)/|v2|^2

	Vector u1 = { v2.x * division, v2.y * division, v2.z * division };

	return u1;
}
Vector orthogonal_projection(const Vector v1, const Vector v2) {

	Vector ort_proj = diff(v1, projection(v1, v2));
	return ort_proj;
}
int convert_2_orthogonal_basis(Vector* v1, Vector* v2, Vector* v3) {
	Vector u1 = *v1;
	Vector u2 = *v2;
	Vector u3 = *v3;
	if ((are_linearly_independent(u1, u2, u3)) == 1) {
		*v2 = diff(*v2, projection(*v2, *v1));
		*v3 = diff(diff(*v3, projection(*v3, *v1)), projection(*v3, *v2));
		return 1;

	}
	else
		return 0;
}

char* vector2str(const Vector v) {
	char* ptr = (char*)malloc(sizeof(char));
	sprintf(ptr, "(%.2f,%.2f,%.2f)", v.x, v.y, v.z);
	return ptr;
}
