#ifndef OPBJECT_H_
#define OPBJECT_H_




class VertexX
{
public:
private:

	float x;

};

class VertexY
{
public:
private:

	float y;

};

class VertexTU
{
public:
private:

	float tu;

};

class VertexTV
{
public:
private:

	float tv;

};

class VertexColor
{
public:
private:
	unsigned long color;
};



class Timer
{
public:
private:
	float time;
};


class Object
{
public:

protected:

	struct CustomVertex
	{
		VertexX x;
		VertexY y;
		VertexColor color;
		VertexTU tu;
		VertexTV tv;
	};

	struct Vec2
	{
		VertexX x;
		VertexY y;	
	};
};




class Character :public Object
{

};

class UI:public Object
{

};

class ScrollStage:public Object
{

};

class Stage :public Object
{

};

#endif


