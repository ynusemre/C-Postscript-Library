#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "postscript.h"


int main(){
	Figure *fig_fx,*fig_polyline,*fig_ellipse,*fig_circle,*fig_polygon;
	Point2D *poly_line,*center1,*center2,*poly_line2,*center3,*center4,*center5;
	Point2D start_roi,end_roi;
	//Point2D *center;

	fig_fx=(Figure*)malloc(sizeof(Figure));
	fig_polyline=(Figure*)malloc(sizeof(Figure));
	fig_ellipse=(Figure*)malloc(sizeof(Figure));
	fig_polygon=(Figure*)malloc(sizeof(Figure));
	fig_circle=(Figure*)malloc(sizeof(Figure));
	

	poly_line=(Point2D*)malloc(sizeof(Point2D));
	poly_line2=(Point2D*)malloc(sizeof(Point2D));
	center1=(Point2D*)malloc(sizeof(Point2D));
	center2=(Point2D*)malloc(sizeof(Point2D));
	center3=(Point2D*)malloc(sizeof(Point2D));
	center4=(Point2D*)malloc(sizeof(Point2D));
	center5=(Point2D*)malloc(sizeof(Point2D));
	

	Color col;
///////////////////////////////  Fx   //////////////////////////////////////////////////////////////
	
	col.red=0;
	col.green=1;
	col.blue=0;
	fig_fx=start_figure(50,50);		
	set_thickness_resolution(fig_fx,0.01,10);
	set_color(fig_fx,col);
	draw_fx(fig_fx,sin,-10,10);
	export_eps(fig_fx,"01-fx.eps");
	
	free(fig_fx);
////////////////////////// RESIZE FIGURE (fx) ////////////////////////////////////////////////////
	col.red=0;
	col.green=1;
	col.blue=0;
	fig_fx=start_figure(50,50);		
	set_thickness_resolution(fig_fx,0.01,10);
	set_color(fig_fx,col);
	draw_fx(fig_fx,sin,-10,10);
	start_roi.x=-12;
	start_roi.y=-12;
	end_roi.x=12;
	end_roi.y=12;
	resize_figure(fig_fx,start_roi,end_roi);
	export_eps(fig_fx,"01-fx(resize).eps");
	
	free(fig_fx);
////////////////////////// SCALE FIGURE (fx) ////////////////////////////////////////////////////
	col.red=0;
	col.green=1;
	col.blue=0;
	fig_fx=start_figure(50,50);		
	set_thickness_resolution(fig_fx,0.01,10);
	set_color(fig_fx,col);
	draw_fx(fig_fx,sin,-10,10);
	scale_figure(fig_fx,4,4);
	export_eps(fig_fx,"01-fx(scale).eps");
	
	free(fig_fx);
/////////////////////////// POLYLINE   //////////////////////////////////////////////////////////////////
	col.red=1;
	col.green=0;
	col.blue=0;
	fig_polyline=start_figure(30,30);
	set_thickness_resolution(fig_polyline,0.01,10);
	set_color(fig_polyline,col);
	draw_polyline(fig_polyline,poly_line,10);
	export_eps(fig_polyline,"02-polyline.eps");
	
	free(fig_polyline);
	free(poly_line);
////////////////////////// RESIZE FIGURE (polyline) ////////////////////////////////////////////////////
	col.red=0;
	col.green=2;
	col.blue=0;
	fig_polyline=start_figure(30,30);
	set_thickness_resolution(fig_polyline,0.01,10);
	set_color(fig_polyline,col);
	draw_polyline(fig_polyline,poly_line,8);
	start_roi.x=-7;
	start_roi.y=-7;
	end_roi.x=7;
	end_roi.y=7;
	resize_figure(fig_polyline,start_roi,end_roi);
	export_eps(fig_polyline,"02-polyline(resize).eps");
	
	free(fig_polyline);
	free(poly_line);
////////////////////////// SCALE FIGURE (polyline) ////////////////////////////////////////////////////
	col.red=0;
	col.green=0;
	col.blue=10;
	fig_polyline=start_figure(30,30);
	set_thickness_resolution(fig_polyline,0.01,10);
	set_color(fig_polyline,col);
	draw_polyline(fig_polyline,poly_line,10);
	scale_figure(fig_polyline,4,4);
	export_eps(fig_polyline,"02-polyline(scale).eps");
	
	free(fig_polyline);
	free(poly_line);
	
/////////////////////////// POLYGON  /////////////////////////////////////////////////////////////////	
	col.red=0;
	col.green=1;
	col.blue=0;
	fig_polygon=start_figure(40,40);
	set_thickness_resolution(fig_polygon,0.01,10);
	set_color(fig_polygon,col);
	draw_polygon(fig_polygon,poly_line2,10);
	export_eps(fig_polygon,"03-polygon.eps");
	
	free(fig_polygon);
	free(poly_line2);
////////////////////////// RESIZE FIGURE (polygon) ////////////////////////////////////////////////////
	col.red=0;
	col.green=1;
	col.blue=0;
	fig_polygon=start_figure(40,40);
	set_thickness_resolution(fig_polygon,0.01,10);
	set_color(fig_polygon,col);
	draw_polygon(fig_polygon,poly_line2,10);
	start_roi.x=-50;
	start_roi.y=-50;
	end_roi.x=50;
	end_roi.y=50;
	resize_figure(fig_polygon,start_roi,end_roi);
	export_eps(fig_polygon,"03-polygon(resize).eps");
	
	free(fig_polygon);
	free(poly_line2);
////////////////////////// SCALE FIGURE (polygon) ////////////////////////////////////////////////////
	col.red=0;
	col.green=1;
	col.blue=0;
	fig_polygon=start_figure(40,40);
	set_thickness_resolution(fig_polygon,0.01,10);
	set_color(fig_polygon,col);
	draw_polygon(fig_polygon,poly_line2,10);
	scale_figure(fig_polygon,1.2,1.2);
	export_eps(fig_polygon,"03-polygon(scale).eps");
	
	free(fig_polygon);
	free(poly_line2);
//////////////////////// ELLIPSE  /////////////////////////////////////////////////////////////////////
	col.red=0;
	col.green=0;
	col.blue=1;
	center1->x =10;
	center1->y =10;
	fig_ellipse=start_figure(50,50);	
	set_thickness_resolution(fig_ellipse,0.01,10);
	set_color(fig_ellipse,col);
	draw_ellipse(fig_ellipse,center1,5,10);
	export_eps(fig_ellipse,"04-ellipse.eps");
	
	free(fig_ellipse);
	free(center1);
////////////////////////// RESIZE FIGURE (ellipse) ////////////////////////////////////////////////////
	col.red=0;
	col.green=1;
	col.blue=0;
	center2->x =10;
	center2->y =10;
	fig_ellipse=start_figure(50,50);	
	set_thickness_resolution(fig_ellipse,0.01,10);
	set_color(fig_ellipse,col);
	draw_ellipse(fig_ellipse,center2,5,10);
	start_roi.x=-50;
	start_roi.y=-50;
	end_roi.x=50;
	end_roi.y=50;
	resize_figure(fig_ellipse,start_roi,end_roi);
	export_eps(fig_ellipse,"04-ellipse(resize).eps");
	
	free(fig_ellipse);
	free(center2);
////////////////////////// SCALE FIGURE (ellipse) ////////////////////////////////////////////////////
	col.red=0;
	col.green=0;
	col.blue=1;
	center3->x =10;
	center3->y =10;
	fig_ellipse=start_figure(50,50);	
	set_thickness_resolution(fig_ellipse,0.01,10);
	set_color(fig_ellipse,col);
	draw_ellipse(fig_ellipse,center3,5,10);
	scale_figure(fig_ellipse,1.5,1.5);
	export_eps(fig_ellipse,"04-ellipse(scale).eps");
	
	free(fig_ellipse);
	free(center3);
//////////////////////// CIRCLE /////////////////////////////////////////////////////////////////////	
	col.red=1;
	col.green=0;
	col.blue=0;
	center4->x =-10;
	center4->y =5;
	fig_circle=start_figure(50,50);	
	set_thickness_resolution(fig_circle,0.01,10);
	set_color(fig_circle,col);
	draw_circle(fig_circle,center4,5);
	export_eps(fig_circle,"05-circle.eps");
	
	free(fig_circle);
	free(center4);
////////////////////////// RESIZE FIGURE (circle) ////////////////////////////////////////////////////
	col.red=1;
	col.green=0;
	col.blue=0;
	center5->x =-10;
	center5->y =5;
	fig_circle=start_figure(50,50);	
	set_thickness_resolution(fig_circle,0.01,10);
	set_color(fig_circle,col);
	draw_circle(fig_circle,center5,5);
	start_roi.x=-16;
	start_roi.y=-16;
	end_roi.x=16;
	end_roi.y=16;
	resize_figure(fig_circle,start_roi,end_roi);
	export_eps(fig_circle,"05-circle(resize).eps");
	
	free(fig_circle);
	
////////////////////////// SCALE FIGURE (circle) ////////////////////////////////////////////////////
	center5=(Point2D*)realloc(center5,2*sizeof(Point2D));	
	
	col.red=1;
	col.green=0;
	col.blue=0;
	center5->x =-10;
	center5->y =5;
	fig_circle=start_figure(50,50);	
	set_thickness_resolution(fig_circle,0.01,10);
	set_color(fig_circle,col);
	draw_circle(fig_circle,center5,5);
	scale_figure(fig_circle,2,2);
	export_eps(fig_circle,"05-circle(scale).eps");
	
	free(fig_circle);
	free(center5);
	
////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	
///////////////////////////////  Fx   //////////////////////////////////////////////////////////////
	
	col.red=0;
	col.green=1;
	col.blue=0;
	fig_fx=start_figure(50,50);		
	set_thickness_resolution(fig_fx,0.01,10);
	set_color(fig_fx,col);
	draw_fx(fig_fx,sin,-10,10);
	
	
/////////////////////////// POLYLINE   //////////////////////////////////////////////////////////////////
	
	col.red=1;
	col.green=0;
	col.blue=0;
	fig_polyline=start_figure(50,50);
	set_thickness_resolution(fig_polyline,0.01,10);
	set_color(fig_polyline,col);
	draw_polyline(fig_polyline,poly_line,10);
	
		
/////////////////////////// POLYGON  /////////////////////////////////////////////////////////////////	
	col.red=0;
	col.green=1;
	col.blue=0;
	fig_polygon=start_figure(50,50);
	set_thickness_resolution(fig_polygon,0.01,10);
	set_color(fig_polygon,col);
	draw_polygon(fig_polygon,poly_line2,10);
	
	
//////////////////////// ELLIPSE  /////////////////////////////////////////////////////////////////////
	
	col.red=0;
	col.green=0;
	col.blue=1;
	center1->x =10;
	center1->y =10;
	fig_ellipse=start_figure(50,50);	
	set_thickness_resolution(fig_ellipse,0.01,10);
	set_color(fig_ellipse,col);
	draw_ellipse(fig_ellipse,center1,5,10);
	
	
//////////////////////// CIRCLE /////////////////////////////////////////////////////////////////////	
	
	col.red=1;
	col.green=0;
	col.blue=0;
	center4->x =-10;
	center4->y =5;
	fig_circle=start_figure(50,50);	
	set_thickness_resolution(fig_circle,0.01,10);
	set_color(fig_circle,col);
	draw_circle(fig_circle,center4,5);
	
///////////////////////////////////////////////////////////////////////////////////////////////////////
	append_figures(fig_fx,fig_polyline);
	append_figures(fig_polyline,fig_circle);
	append_figures(fig_circle,fig_ellipse);
	

	export_eps(fig_fx,"all_figure.eps");
	
	free(fig_fx);
	free(fig_polyline);
	free(fig_polygon);
	free(fig_ellipse);
	free(fig_circle);
	free(poly_line);
	free(poly_line2);
	free(center1);
	free(center4);
/////////////////////////////////////////////////////////////////////////////////////////////
	
	return 0;
}