//If a class contains or inherits one or more virtual functions, then four additional bytes (or eight bytes if the target hardware uses 64-bit addresses) are added to the class layout
//These four or eight bytes are collectively called the virtual table pointer
//If you expand the class in QuickWatch or Variables window , you can see class details in ascii like so.
//Here you can see that the class is of type Triangle and has a virtual table with two functions called SetId and Draw

struct Vector3
{
	float x;
	float y;
	float z;
};

class Shape
{
public:
	
	virtual void SetId(int id) { m_id = id; }
	int GetId() const { return m_id; }
	virtual void Draw() = 0; // pure virtual -- no impl.
private:
	int m_id;
};
class Circle : public Shape
{
public:
	void SetCenter(const Vector3& c) { m_center = c; }
	Vector3 GetCenter() const { return m_center; }
	void SetRadius(float r) { m_radius = r; }
	float GetRadius() const { return m_radius; }
	virtual void Draw()
	{
		// code to draw a circle
	}
private:
	Vector3 m_center;
	float m_radius;
};

class Triangle : public Shape
{
public:
	void SetVertex(int i, const Vector3& v) { m_vtx[i] = v;  }
	Vector3 GetVertex(int i) const { return m_vtx[i]; }
	virtual void Draw()
	{
		// code to draw a triangle
	}
	virtual void SetId(int id)
	{
		// call base class' implementation
		Shape::SetId(id);
		// do additional work specific to Triangles...
	}
private:
	Vector3 m_vtx[3];
};
// -----------------------------
void main(int, char**)
{
	Shape* pShape1 = new Circle;
	Shape* pShape2 = new Triangle;
	pShape1->Draw();
	pShape2->Draw();
	// ...
}