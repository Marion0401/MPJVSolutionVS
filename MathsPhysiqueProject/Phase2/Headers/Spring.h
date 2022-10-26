#ifndef Spring_H
#define Spring_H

class Spring : public Force {

	
	const float l0;
	const float k;
	float l;
	Particle particle;

	public:
		Spring(const float l0,const float k, float l, Particle particle) : part(p) {};

		const float getL0() const { return l0; }
		const float getK() const { return k; }
		float getL() { return l; }
		Particle getPartcile() { return particle; }

		void getL0(float l0);
		void getK(float k);
		void getL(float l);
		void getParticle(Particle particle);
	

		override void update (float deltatime);

};
#endif

