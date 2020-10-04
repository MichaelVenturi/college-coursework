#ifndef SEQUENCE_H
#define SEQUENCE_H
template <class value_type>
class sequence
{
public:
	sequence();
	sequence(int size);
	~sequence();
	bool full() const;
	bool empty()const;
	int num_element()const;
	int max_capacity()const;
	value_type at(int position) const;
	void set(const value_type& entry, int position);
	void insert(const value_type& entry, int position);
	void push_back(const value_type& entry);
	void remove_current(int position);
	void print()const;

	void expand();
private:
	value_type* data;
	int num_used;
	int capacity;
};
#endif
