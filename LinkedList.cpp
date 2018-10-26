// LinkedList.cpp
//Modifeied by jacob Silva
//COSC 2030

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.
#include "stdafx.h"
#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

int List::size()
{
	int count = 0;
	Node* temptr = first_;
	while (temptr != NULL)
	{
		temptr = temptr->next_;
		count++;

	}
	return count;
}

double List::sum()
{
	double sum = 0, x = 0;
	if (!empty())
	{
		x = first_->entry_;
		sum = sum + x;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			sum = sum + ptr->entry_;
			ptr = ptr->next_;
		}
	}
	return sum;
}

void List::insertAsLast(double x)
{
	Node * lastNode = new Node(x, NULL);
	Node * ptr = first_;

	while (ptr->next_ != NULL)
	{
		ptr = ptr->next_;
	}

	ptr->next_ = new Node(x, NULL);

	//last->entry_ = x;
	//Node*ptr = first_->next_;
	//Node* last= new Node(x);
	//while (ptr != NULL)
	//{
	//ptr = ptr->next_;
	//}
	//if (ptr == NULL)
	//{
	//ptr = last;

	//}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

/*bool List::operator==(const List &rhs) {
if (size() == 0 && rhs.size() == 0) { return true; }//both empty
if (size() != rhs.size()) { return false; }//sizes not the same
Node * lptr = this->next_;
Node * rptr = rhs->next_;
Double lEntry = lptr->entry_;
Double rEntry = rptr->entry_;
while (lptr != NULL && rptr != NULL)
{
if (lEntry != rEntry) {
return false;
}
lptr = lptr->next_;
rptr = rptr->next_;
lEntry = lptr->entry_;
rEntry = rptr->entry_;
}
return true;
}
*/

bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);

}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;

}

double List:: max()
{
	double max = 0;
	if (!empty())
	{
		max= first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			if (max < ptr->entry_)
			{
				max = ptr->entry_;
			}
			ptr = ptr->next_;
		}
	}
	return max;
}

double List::min()
{
	double min = 0;
	if (!empty())
	{
		min = first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			if (min > ptr->entry_)
			{
				min = ptr->entry_;
			}
			ptr = ptr->next_;
		}
	}
	return min;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}

