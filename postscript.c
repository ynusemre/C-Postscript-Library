#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "postscript.h"
/*  a new figure */
Figure * start_figure(double width, double height){
	Figure *fig=(Figure *)malloc(sizeof(Figure));

	fig->urx=width/2.0;
	fig->ury=height/2.0;

	fig->llx=(-width)/2.0;
	fig->lly=(-height)/2.0;

	return fig;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*thickness and resolution of the figures*/

void set_thickness_resolution(Figure * fig, double thickness, double resolution){
	fig->resolution=resolution;
	fig->thickness=thickness;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*the colors of the figures*/

void set_color(Figure * fig, Color c){
	fig->col.red=c.red;
	fig->col.green=c.green;
	fig->col.blue=c.blue;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*for a new a new point*/
void add(Point2D *r,double x,double y){
	while(r->next!=NULL){
		r=r->next;
	}
	r->next=(Point2D*)malloc(sizeof(Point2D));
	r->next->x=x;
	r->next->y=y;
	r->next->next=NULL;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*the function that draws the given function in the figure initialized by “start_figure”. 
the figure was drawn the function for each step within the range defined by “start_x” and “end_x”.
the figure is not smaller in length than the resolution defined in “resolution”.
 The lines drawing the graphs have the thickness in the given same-named argument.*/
void draw_fx(Figure * fig, double f(double x), double start_x, double end_x){
	Point2D *iter;
	iter=(Point2D*)malloc(sizeof(Point2D));
	
	iter->x=start_x;
	iter->y=f(start_x);
	iter->next=NULL;
	
	while(start_x<end_x){
		start_x=start_x+(1.0/fig->resolution);
		add(iter,start_x,f(start_x));
	}
	add(iter,end_x,f(end_x));

	fig->point=iter;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/*polyline created with  each point  connected from the first point to the last in the given order.*/
void draw_polyline(Figure *fig,Point2D *poly_line,int n){
	Point2D *iter=(Point2D*)malloc(sizeof(Point2D));

	iter->x=poly_line[0].x;
	iter->y=poly_line[0].y;
	iter->next=NULL;

	for(int i=0;i<n;i++){
		add(iter,i,(i*i));
	}
	fig->point=iter;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*create polygon by drawing a final line
between first and the last point.*/
void draw_polygon(Figure *fig,Point2D * poly_line,int n){
	Point2D *iter=(Point2D*)malloc(sizeof(Point2D));
	iter->next=NULL;
	
	for(int i=0;i<n;i++){
		add(iter,poly_line[i].x,poly_line[i].y);
	}
	
	add(iter,poly_line[0].x,poly_line[0].y);
	fig->point=iter;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*i created ellipse centred around the centre with the given width and height.
 I combined the upper half of the figure with the lower half.   */
void draw_ellipse(Figure *fig, Point2D *center, double x,double y){
	double start_x=-x;
	double end_x=x;
	double count1=0.0;
	double count2=0.0;
	Point2D *iter=(Point2D*)malloc(sizeof(Point2D));

	iter->x = start_x + center->x;
	iter->y =sqrt((1-(pow(start_x,2)/pow(x,2)))*pow(y,2)) + center->y;
	iter->next=NULL;

	while(start_x < end_x){
		count1=start_x + center->x;
		count2=sqrt((1-(pow(start_x,2)/pow(x,2)))*pow(y,2)) + center->y;
		start_x=start_x+1.0/fig->resolution;
		add(iter,count1,count2);
		
	}
	start_x =x; 
	end_x =-x;
	count1=0.0;
	count2=0.0;
	while(start_x > end_x){
		count1=start_x + center->x;
		count2=-(sqrt((1-(pow(start_x,2)/pow(x,2)))*pow(y,2))) + center->y;
		start_x=start_x-1.0/fig->resolution;
		add(iter,count1,count2);
		
	}
	count1=0.0;
	count2=0.0;
	count1= end_x + center->x;
	count2= -(sqrt((1-(pow(end_x,2)/pow(x,2)))*pow(y,2))) + center->y;
	add(iter,count1,count2);
	fig->point=iter;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*I created the circle shape for the tree structure. But I could not create the tree structure :D .
The logic of the formation of the circle is similar to the ellipse.*/
void draw_circle(Figure *fig, Point2D *center, double radius){
	double start_x=-radius;
	double end_x=radius;
	double count1=0.0;
	double count2=0.0;
	Point2D *iter=(Point2D*)malloc(sizeof(Point2D));

	iter->x = start_x + center->x;
	iter->y =sqrt((1-(pow(start_x,2)/pow(radius,2)))*pow(radius,2)) + center->y;
	iter->next=NULL;

	while(start_x < end_x){
		count1=start_x + center->x;
		count2=sqrt((1-(pow(start_x,2)/pow(radius,2)))*pow(radius,2)) + center->y;
		start_x=start_x+1.0/fig->resolution;
		add(iter,count1,count2);
		
	}
	start_x =radius; 
	end_x =-radius;
	count1=0.0;
	count2=0.0;
	while(start_x > end_x){
		count1=start_x + center->x;
		count2=-(sqrt((1-(pow(start_x,2)/pow(radius,2)))*pow(radius,2))) + center->y;
		start_x=start_x-1.0/fig->resolution;
		add(iter,count1,count2);
		
	}
	count1=0.0;
	count2=0.0;
	count1= end_x + center->x;
	count2= -(sqrt((1-(pow(end_x,2)/pow(radius,2)))*pow(radius,2))) + center->y;
	add(iter,count1,count2);
	fig->point=iter;	
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*Scales the figures in both dimensions by scale_x and scale_y*/
void scale_figure(Figure *fig,double scale_x, double scale_y){
	Point2D *iter=fig->point;
	
	
		while(iter!=NULL){
			iter->x=iter->x*scale_x;
			iter->y=iter->y*scale_y;
			iter=iter->next;
		}
		
	
}	
/////////////////////////////////////////////////////////////////////////////////////////////
/*function that changes the size of the figures by start_roi and end_roi.*/
void resize_figure(Figure* fig,Point2D start_roi,Point2D end_roi){
	fig->llx=start_roi.x; 
	fig->lly=start_roi.y; 

	fig->urx=end_roi.x;		
	fig->ury=end_roi.y;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*Function that merges two figures.*/
void append_figures(Figure *fig1,Figure *fig2){
	while(fig1->next!=NULL){
		fig1=fig1->next;
	}
	fig1->next=fig2;
}
/////////////////////////////////////////////////////////////////////////////////////////////
/*Exports the current figure to an EPS file. */
void export_eps(Figure *fig,char *file_name){
	FILE *fp=fopen(file_name,"w");
	
	if(!fp){							   // if file doesn't open....
		printf("File didn't open.");
		exit(1);
	}
	fprintf(fp,"%%!PS-Adobe-3.0 EPSF-3.0\n");
	fprintf(fp,"%%%%BoundingBox: %.3lf %.3lf %.3lf %.3lf\n",fig->llx,fig->lly,fig->urx,fig->ury);
	
	while(fig!=NULL){	
		fprintf(fp,"%.3lf setlinewidth\n",fig->thickness);
		fprintf(fp,"%.3lf %.3lf %.3lf setrgbcolor\n",fig->col.red,fig->col.green,fig->col.blue);
		if(fig->text!=NULL){
			while(fig->text!=NULL){
				fprintf(fp,"%d %d moveto",(int)fig->text->x,(int)fig->text->y);
				fprintf(fp,"(%d) show",fig->text->number);
				fig->text=fig->text->next;
			}
		}
		if(fig->point!=NULL){
			fprintf(fp,"%.3lf %.3lf moveto\n",fig->point->x,fig->point->y);
				while(fig->point!=NULL){
					fprintf(fp, "%.3lf %.3lf lineto\n",fig->point->x,fig->point->y);
					fig->point=fig->point->next; 					
				}
				fprintf(fp,"stroke\n");
		}
		fig=fig->next;
	}
	fprintf(fp,"stroke\n");
	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////////////////////