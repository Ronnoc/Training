import urllib2,json

oxfordhk="https://oxfordhk.azure-api.net/academic/v1.0/evaluate?"
attributes="&attributes=Id,F.FId,J.JId,C.CId,AA.AuId,AA.AfId,RId"
key="&subscription-key=f7cc29509a8443c5b3a5e56b0e38b5a6"
count="&count=10000"

def askId(id):#askId(2143554828)
	url = oxfordhk+"expr=Id="+str(id)+count+attributes+key
	strHtml=urllib2.urlopen(url).read()
	return json.loads(strHtml)['entities'][0]  

def askAuid(Auid):#askAuid(2099495348)
	url = oxfordhk+"expr=Composite(AA.AuId="+str(Auid)+")"+count+attributes+key
	strHtml=urllib2.urlopen(url).read()
	return json.loads(strHtml)['entities']

def selfid(id,info):#[id ? id] ?!=id
	result=[]
	if(info.has_key('F')):
		for val in info['F']:
			result.append(val['FId'])
	if(info.has_key('C')):result.append(info['C']['CId'])
	if(info.has_key('J')):result.append(info['J']['JId'])
	for var in info['AA']:
		result.append(var['AuId'])
	return result

def checkFid(info1,info2):
	result=[]
	if(info1.has_key('F') and info2.has_key('F')):
		for var in info1['F']:
			if(var in info2['F']):
				result.append(var['FId'])
	return result

def checkAuid(info1,info2):
	result=[]
	for ren1 in info1['AA']:
		for ren2 in info2['AA']:
			if(ren1['AuId']==ren2['AuId']):
				result.append(ren1['AuId'])
	return result

def id2id(id1,info1,referlist,id2,info2,cnt):
	'''
	[id,id]
	[id,id,id]
	[id,F.Fid,id]	[id,C.Cid,id]	[id,J.Jid,id]	[id,Auid,id]
	[id,id,id,id]
	[id,id,F.Fid,id]	[id,F.Fid,id,id]
	[id,id,C.Cid,id]	[id,C.Cid,id,id]
	[id,id,J,Jid,id]	[id,J.Jid,id,id]
	[id,id,Auid,id]		[id,Auid,id,id]
	'''
	result=[]
	if(id1==id2):#todo [id,?,id,id]
		mid=selfid(id1,info1)
		for var in mid:
			result.append([id1,var,id1])
		if(cnt>=3):
			for ref in referlist:#[id1,ref,?,id1]
				fidlist=checkFid(ref,info1)
				for fit in fidlist:
					result.append([id1,ref['Id'],fit,id1])
				auidlist=checkAuid(ref,info1);
				for peo in auidlist:
					result.append([id1,ref['Id'],peo,id1])
				if(ref.has_key('C') and info1.has_key('C')):
					if(ref['C']['CId']==info1['C']['CId']):
						result.append([id1,ref['Id'],info1['C']['CId'],id1])
				if(ref.has_key('J') and info1.has_key('J')):
					if(ref['J']['JId']==info1['J']['JId']):
						result.append([id1,ref['Id'],info1['J']['JId'],id1])
		return result
	if(id2 in info1['RId']):#[id,id]
		result.append([id1,id2])
	for ref in referlist:#[id,id,id]
		if(id2 in ref['RId']):
			result.append([id1,ref['Id'],id2])
	#todo [id1,id?,id?,id2]
	#todo [id1,*,id?,id2]
	if(info2.has_key('F')):#[id,F,id],[id,id,F,id]
		fidlist=checkFid(info1,info2)
		for fit in fidlist:
			result.append([id1,fit,info2])
		if(cnt>=3):
			for ref in referlist:
				fidlist=checkFid(ref,info2)
				for fit in fidlist:
					result.append([id1,ref['Id'],fit,id2])
	if(info2.has_key('C')):
		if(info1.has_key('C') and info1['C']['CId']==info2['C']['CId']):
			result.append([id1,info1['C']['CId'],id2])
		if(cnt>=3):
			for ref in referlist:
				if(ref.has_key('C')and ref['C']['CId']==info2['C']['CId']):
					result.append([id1,ref['Id'],ref['C']['CId'],id2])
	if(info2.has_key('J')):
		if(info1.has_key('J') and info1['J']['JId']==info2['J']['JId']):
			result.append([id1,info1['J']['JId'],id2])
		if(cnt>=3):
			for ref in referlist:
				if(ref.has_key('J')and ref['J']['JId']==info2['J']['JId']):
					result.append([id1,ref['Id'],ref['J']['JId'],id2])

	auidlist=checkAuid(info1,info2);
	for peo in auidlist :
		result.append([id1,peo,id2])
	if(cnt>=3):
		for ref in referlist:
			auidlist=checkAuid(ref,info2)
			for peo in auidlist:
				result.append([id1,ref['Id'],peo,id2])
	return result

def id2auid(id1,info1,referlist,auid2,auinfo2,cnt):
	'''
	#[id,au]
	#[id,id,au]
	#[id,id,id,au],[id,fid,id,au],[id,cid,id,au],[id,jid,id,au],[id,au,id,au]
	#[id,au,af,au]
	'''
	result=[]
	afid2=set([]);
	for paper in auinfo2:
		for peo in paper['AA']:
			if(peo['AuId']==auid2 and peo.has_key('AfId')):
				afid2.add(peo['AfId'])
	for peo in info1['AA']:
		if(peo['AuId']==auid2):
			result.append([id1,auid2])
		if(peo.has_key('AfId') and peo['AfId'] in afid2):
			result.append([id1,peo['AuId'],peo['AfId'],auid2])
	for paper in auinfo2:
		if(paper['Id'] in info1['RId']):
			result.append([id1,paper['Id'],auid2])
		ways=id2id(id1,info1,referlist,paper['Id'],paper,2);
		for way in ways:
			result.append(way+[auid2])
	return result

def auid2id(auid1,auinfo1,id2,info2,cnt):
	'''
	#[au,id]
	#[au,id,?,id]
	#[au,af,au,id]
	'''
	result=[]
	for paper in auinfo1:
		if(paper['Id']==id2):
			result.append([auid1,id2])
		referlist=[]
		for ref in paper['RId']:
			referlist.append(askId(ref));#timelimit
		ways=id2id(paper['Id'],paper,referlist,id2,info2,2)
		for way in ways:
			result.append([auid1]+way)
	afid1=set([]);
	for paper in auinfo1:
		for peo in paper['AA']:
			if(peo['AuId']==auid1 and peo.has_key('AfId')):
				afid1.add(peo['AfId'])
	for peo in info2['AA']:
		if(peo.has_key('AfId') and peo['AfId'] in afid1):
			result.append([auid1,peo['AfId'],peo['AuId'],id2])
	return result

def auid2auid(auid1,auinfo1,auid2,auinfo2,cnt):
	'''
	#[au,af,au]
	#[au,id,au]
	#[au,id,id,au]
	'''
	result=[]
	afid1=set([]);
	for paper in auinfo1:
		for peo in paper['AA']:
			if(peo['AuId']==auid1 and peo.has_key('AfId')):
				afid1.add(peo['AfId'])
	afid2=set([]);
	for paper in auinfo2:
		for peo in paper['AA']:
			if(peo['AuId']==auid2 and peo.has_key('AfId')):
				afid2.add(peo['AfId'])
	afid0=afid1&afid2
	for pof in afid0:
		result.append([auid1,pof,auid2])
	for paper in auinfo1:
		for peo in paper['AA']:
			if(peo['AuId']==auid2):
				result.append([auid1,peo['AuId'],auid2]);
	for paper in auinfo1:
		ridset = set(paper['RId'])
		for paper2 in auinfo2:
			if(paper2['Id'] in ridset):
				result.append([auid1,paper['Id'],paper2['Id'],auid2])
	return result

def solve(id1,id2):
	auinfo1,auinfo2=askAuid(id1),askAuid(id2)
	info1,info2=askId(id1),askId(id2)
	if(len(auinfo1)==0 and len(auinfo2)==0):
		referlist=[]
		for ref in info1['RId']:
			referlist.append(askId(ref));
		return id2id(id1,info1,referlist,id2,info2,3);
	if(len(auinfo1)==0 and len(auinfo2)!=0):
		referlist=[]
		for ref in info1['RId']:
			referlist.append(askId(ref));
		return id2auid(id1,info1,referlist,id2,auinfo2,3);
	if(len(auinfo1)!=0 and len(auinfo2)==0):
		return auid2id(id1,auinfo1,id2,info2,3);
	if(len(auinfo1)!=0 and len(auinfo2)!=0):
		return auid2auid(id1,auinfo1,id2,auinfo2,3);
	return [[id1,id2]]

print solve(2145115012,2140251882)
#id1=2145115012&id2=2140251882