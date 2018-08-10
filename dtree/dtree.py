file=open("ver_data.txt")
s=file.readlines()
file.close()

in_data=[]

for rec in s:
	in_data.append(rec.rstrip('\n').split('\t'))

attri_no=len(in_data[0])-1
attr_list=[1 for i in range(attri_no)]

class node:
	lable='not defined'
	temp_lable=''
	test_condition_num=0
	data=[]
	child={}

def distribute(data,i):
	mp={}
	for record in data:
		if(record[i] in mp):
			mp[record[i]].append(record)
		else:
			mp[record[i]]=[record]
	l=list(mp.values())
	return l

def find_gini(data):
	total_rec=len(data)
	mp={}
	for record in data:
		if(record[-1] in mp):
			mp[record[-1]]=mp[record[-1]]+1
		else:
			mp[record[-1]]=1

	class_count=list(mp.values())
	gini=0;
	for i in class_count:
		gini=gini+(i/total_rec)**2
	gini=1-gini
	return gini

def find_test_condition(data):
	total_rec_parent=len(data)
	best_test_condition=0
	gini_par=find_gini(data)
	max_gain=0

	for i in range(attri_no):
		if(attr_list[i]==1):
			l=distribute(data,i)
			wt_gini_dist=0
			for d in l:
				wt_gini_dist=wt_gini_dist+(len(d)/total_rec_parent)*find_gini(d)
			gain=gini_par-wt_gini_dist
			if(gain>max_gain):
				max_gain=gain
				best_test_condition=i
	if(max_gain==0):
		return -1
	elif(max_gain>0):
		return best_test_condition
	else:
		return -2


def build(root):
	temp=root.data[0][-1]
	flag=True
	for record in root.data:
		if(record[-1]!=temp):
			flag=False
			break
	if(flag):
		root.lable=temp
		return
	
	mp={}
	for record in root.data:
		if(record[-1] in mp):
			mp[record[-1]]=mp[record[-1]]+1
		else:
			mp[record[-1]]=1
	temp_lable=list(mp.values())
	temp_lable=temp_lable.index(max(temp_lable))
	temp_lable=list(mp.keys())[temp_lable]
	root.temp_lable=temp_lable

	root.test_condition_num=find_test_condition(root.data)
	
	if(root.test_condition_num==-1):
		root.lable=temp_lable
		return
	
	elif(root.test_condition_num==-2):
		print("getting -ve gain on the node")
		root.lable=temp_lable
		return
	
	attr_list[root.test_condition_num]=0

	child_data=distribute(root.data,root.test_condition_num)

	for i in child_data:
		root.child[i[0][root.test_condition_num]]=node()
		root.child[i[0][root.test_condition_num]].data=i

	k=list(root.child.keys())

	for c in k:
		build(root.child[c])

def classify(record,root):
	if(root.lable!="not defined"):
		return root.lable
		

	t_c_n=root.test_condition_num
	t_c_val=record[t_c_n]

	if(t_c_val in root.child):
		return classify(record,root.child[t_c_val])
	else:
		return root.temp_lable


root=node()
root.data=in_data
print("starting the build")
build(root)
print("build finished")

while(True) :
	print()
	print("enter record to classify or press 'x' to exit:")
	print("bt  skin birth  aqua arial legs hibernation")
	record=input()
	if(record=='x'):
		break

	record=record.strip().split(' ')
	if(len(record)!=attri_no):
		print("invalid record entered")
		continue
	class_lable=classify(record,root)
	print("class lable: ")
	print(class_lable)
