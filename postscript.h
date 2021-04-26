#ifndef postscript
#define postscript

struct colors_objects{
	double red;
	double green;
	double blue;
};
typedef struct colors_objects Color;
/////////////////////////////////////////////////////////////////////////////////////////////
struct Point2D_objects{
	double x;
	double y;
	struct Point2D_objects *next;
};
typedef struct Point2D_objects Point2D;
/////////////////////////////////////////////////////////////////////////////////////////////
struct Text_Pdf{
	double x;
	double y;
	int number;
	struct Text_Pdf *next; 
};
typedef struct Text_Pdf Text;
/////////////////////////////////////////////////////////////////////////////////////////////
struct Figure_objects{
	double urx; 
	double ury; 
	double llx; 
	double lly;
	double thickness;
	double resolution;
	
	
	Color col;
	Point2D *point;
	Text *text;
	struct Figure_objects *next;
};
typedef struct Figure_objects Figure;
/////////////////////////////////////////////////////////////////////////////////////////////
struct tree{
	int data;
	struct tree *right;
	struct tree *left;
};
typedef struct tree Tree;
/////////////////////////////////////////////////////////////////////////////////////////////
Figure * start_figure(double width, double height);
void set_thickness_resolution(Figure * fig, double thickness, double resolution);
void set_color(Figure * fig, Color c);
void add(Point2D *r,double x,double y);
void draw_fx(Figure * fig, double f(double x), double start_x, double end_x);
void draw_polyline(Figure *fig,Point2D *poly_line,int n);
void draw_polygon(Figure *fig,Point2D * poly_line,int n);
void draw_ellipse(Figure *fig, Point2D *center, double x,double y);
void draw_circle(Figure *fig, Point2D *center, double radius);
void scale_figure(Figure *fig,double scale_x, double scale_y);
void resize_figure(Figure* fig,Point2D start_roi,Point2D end_roi);
void append_figures(Figure *fig1,Figure *fig2);
void export_eps(Figure *fig,char *file_name);

#endif