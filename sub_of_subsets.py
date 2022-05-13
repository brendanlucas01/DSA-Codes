import copy

class sub_of_subset:
	def __init__(self):
		self.store_result = []
		self.items = []
		self.target = 0
		self.final_index = 0
		
	def get_subsets(self,i,thisset):
		sum_set = sum(thisset)
		if i == self.final_index:
			if sum_set == self.target:
				self.store_result.append(copy.deepcopy(thisset))
				return True
			else:
				return False
		else:
			if sum_set == self.target:
				self.store_result.append(thisset)
				return True
			elif sum_set>self.target:
				return False
			else:
				copied = copy.copy(thisset)
				self.get_subsets(i+1,copied)
				copied.append(self.items[i])
				self.get_subsets(i+1,copied)
				
		
sub_of_set = sub_of_subset()
sub_of_set.items = [int(x) for x in input("Enter the items of set: ").split()]
sub_of_set.target=int(input("Enter the Target weight: "))
sub_of_set.final_index = len(sub_of_set.items)
sub_of_set.get_subsets(0,[])
print(sub_of_set.store_result)