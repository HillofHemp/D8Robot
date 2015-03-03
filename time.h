class time
{ 
	private:
	double start;

	public:
	void tic();
	void area();
	
}	
	
void tic()
{
	start = TimeNow();
}

double toc()
{
	return TimeNow() - start;
}
