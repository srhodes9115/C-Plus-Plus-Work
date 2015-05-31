// Distance function to compute the distance between two coordinates
double distance (double x1, double y1, double x2, double y2)
{
	double dist;
	dist = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
	return dist;
}
//Radius function to compure the radius between two coordinates
double radius (double x1, double y1, double x2, double y2)
{
	double rad;
	rad = distance(x1,y1,x2,y2);
	return rad; 
}
//Circumference function to compute the circumference given the radius
double circumference (double rad)
{
    return 2*4*atan(1)*rad; 
}
//Area function to computre the area given the radius
double area (double rad)
{
	return 4*atan(1)*rad*rad;
}
