#ifndef NEUTRON_H
#define NEUTRON_H



class Neutron
	{

	public:

	Neutron();
	Neutron(float x, float y, float z, float theta, float phi, float energy);
	Neutron(Neutron &n);
	Neutron& operator=(const Neutron& source);
	virtual ~Neutron();


	float GetX(){return fx;}
	float GetY(){return fy;}
	float GetZ(){return fz;}
	float GetTheta(){return ftheta;}
	float GetPhi(){return fphi;}
	float GetEnergy(){return fenergy;}

	void SetX(float x){fx=x;}
	void SetY(float y){fy=y;}
	void SetZ(float z){fz=z;}
	void SetPhi(float phi){fphi=phi;}
	void SetTheta(float theta){ftheta=theta;}
	void SetEnergy(float energy){fenergy=energy;}


	private:

	float fx, fy, fz;
	float ftheta, fphi, fenergy;



	ClassDef(Neutron,1);
	};

#endif
