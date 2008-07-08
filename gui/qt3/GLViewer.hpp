/*************************************************************************
*  Copyright (C) 2004 by Olivier Galizzi, Janek Kozicki                  *
*  2008 Václav Šmilauer
*  *
*  This program is free software; it is licensed under the terms of the  *
*  GNU General Public License v2 or later. See file LICENSE for details. *
*************************************************************************/
#pragma once

#include<yade/core/Omega.hpp>
#include<yade/pkg-common/OpenGLRenderingEngine.hpp>
#include<yade/lib-QGLViewer/qglviewer.h>
#include<yade/lib-QGLViewer/constraint.h>
#include<set>

/*! Class handling user interaction with the openGL rendering of simulation.
 *
 * Clipping planes:
 * ================
 *
 * Clipping plane is manipulated after hitting F1, F2, .... To end the manipulation, press Escape.
 *
 * Keystrokes during clipping plane manipulation:
 * * space activates/deactives the clipping plane
 * * x,y,z aligns the plane with yz, xz, xy planes
 * * left-double-click aligns the plane with world coordinates system (canonical planes + 45˚ interpositions)
 * * 1,2,... will align the current plane with #1, #2, ... (same orientation)
 * * r reverses the plane (normal*=-1)a
 *
 * Keystrokes that work regardless of whether a clipping plane is being manipulated:
 * * Alt-1,Alt-2,... adds/removes the respective plane to bound group:
 * 	mutual positions+orientations of planes in the group are maintained when one of those planes is manipulated
 *
 * Clip plane number is 3; change OpenGLRenderingEngine::clipPlaneNum, complete switches "|| ..." in keyPressEvent
 * and recompile to have more.
 */

class GLViewer : public QGLViewer
{	
	Q_OBJECT 
	
	friend class QGLThread;
	protected:
		shared_ptr<OpenGLRenderingEngine> renderer;
	private :
		bool 			drawGridXYZ[3];
		bool			isMoving;
		bool			wasDynamic;
		float			cut_plane;
		int			cut_plane_delta;
		int manipulatedClipPlane;
		set<int> boundClipPlanes;
		shared_ptr<qglviewer::LocalConstraint> xyPlaneConstraint;
		string strBoundGroup(){string ret;FOREACH(int i, boundClipPlanes) ret+=" "+lexical_cast<string>(i+1);return ret;}
		void centerMedianQuartile();

     public :
		GLViewer (int id, shared_ptr<OpenGLRenderingEngine> _renderer, QWidget * parent=0, QGLWidget * shareWidget=0);
		virtual ~GLViewer (){};
		virtual void draw();
		virtual void drawWithNames();
		void centerScene();
		void mouseMovesCamera();
		void mouseMovesManipulatedFrame(qglviewer::Constraint* c=NULL);
		void resetManipulation();
		void startClipPlaneManipulation(int planeNo);
		int viewId;


		DECLARE_LOGGER;
	protected :
		virtual void keyPressEvent(QKeyEvent *e);
		virtual void postDraw();
		virtual void closeEvent(QCloseEvent *e);
		virtual void postSelection(const QPoint& point);
		virtual void endSelection(const QPoint &point);
		virtual void mouseDoubleClickEvent (QMouseEvent *e);
};
