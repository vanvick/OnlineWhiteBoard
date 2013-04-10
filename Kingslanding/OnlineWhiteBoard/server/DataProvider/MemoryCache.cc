#include "MemoryCache.h"

using namespace Kingslanding.OnlineWhiteBoard.ServerData.Provider;

MemoryCache::MemoryCache(int maxsize)
{
  state_ = false;
  
  try
  {
    operation_[0] = new Operation*[capacity];
    operation_[1] = new Operation*[capacity];
  }
  catch(std::bad_alloc&)
  {
    
  }
}

MemoryCache::~MemoryCache()
{
  if(operation_[0])
  {
    for(int i = 0;i<size_[0];i++){
      index_ = front_[0];
      delete operation_[0][index_];
      front_[0]++;
    }
    delete []operation_[0];
    
  }
  
  if(operation_[1])
  {
    for(int i = 0;i<size_[1];i++){
      index_ = front_[1];
      delete operation_[1][index_];
      front_[1]++;
    }
    delete []operation_[1];
    
  }
  
}

int MemoryCache::IsEmpty() const
{

    return 0==(state_?size_[1]:size_[0]);
}

int MemoryCache::GetCount() const
{
    return state_?size_[1]:size_[0];
    
}

int MemoryCache::IsFull() const
{
    return capacity==(state_?size_[1]:size_[0]);
}

bool MemoryCache::set_state()
{
  
    if(state_)
    {
      rear[0]=0;
      front_[0]=0;
      size_[0]=0;
      front_id[0]=0;  
      rear_id[0]=0;
    }
    else
    {
      rear[1]=0;
      front_[1]=0;
      size_[1]=0;
      front_id[1]=0;
      rear_id[1]=0;
    }
    state_=state_?false:true;
    
}


bool MemoryCache::add_Operation(const Operation& oper)
{
  if(state_){
    add_operation_to_set(1,oper);
  }
  else
  {
    add_operation_to_set(0,oper);
  }
  
  return true;
}

bool MemoryCache::add_operation_to_set(int set,const Operation& oper)
{
    if(IsEmpty()){
      front_id[set]=oper.serial_number();
      rear_id[set]=oper.serial_number();
    }
    if(IsFull())
    {
      index_=front_[set];
      rear[set]=index_;
      delete operation_[set][index_];
      *operation_[set][index_]=oper;
      
      front_[set]++;
      front_[set]/=capacity;
      index_=front_[set];
      front_id[set]=*operation_[set][index_]->serial_number();
      
    }
    else
    {
      size_[set]++;
      rear[set]++;
      rear[set]/=capacity;
      index_=rear[set];
      *operation_[set][index_]=oper;
    }
    
    rear_id[set]=oper.serial_number();
    
    return true;
}

Operation* MemoryCache::get_Operation_After(int operation_id, int& size_)
{
  
}

Operation* MemoryCache::get_operation_from_set(int set, int operation_id, int& size_)
{
  if()
}







