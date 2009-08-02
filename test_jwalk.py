"""
  This is a simple python script to test the autogenerated module

"""
import os
import sys
import time

path = `os.environ.get("AL_DIR")`
home = `os.environ.get("HOME")`

#Checking AL_DIR
if path == "None":
        print "the environnement variable AL_DIR is not set, aborting..."
        sys.exit(1)
else:
        alPath = path + "/extern/python/aldebaran"
        alPath = alPath.replace("~", home)
        alPath = alPath.replace("'", "")
        sys.path.append(alPath)
# import NaoQi lib
        
        import naoqi
        from naoqi import ALBroker
        from naoqi import ALModule
        from naoqi import ALProxy
        from naoqi import ALBehavior



# Put here IP and Port of a broker containg JWalk        
IP="127.0.0.1"
PORT=9559

#________________________________
# Generic Proxy creation 
#________________________________
def main():
	print '        START TESTING JWalk MODULE'
	try:
		JWalk_Proxy = ALProxy("JWalk",IP,PORT)
	except Exception,e:
		print "Error when creating JWalk  proxy:"
		print str(e)
		return(1)
	#________________________________
	# Remote procedure call
	#________________________________
	inParam = ["test", 1, 45, [123, 456, "789"]]

	try:
		ret = JWalk_Proxy.DummyFunction( "hello, world", inParam )
	except Exception,e:
		print "JWalk test Failed"
		return(1)

	print 'Returned Value : '
	print(ret)
	if (ret == inParam):
		print 'Success, the return value is correct'
		print '            JWalk MODULE TESTED'
		print ''
		return(0)
	else:
		print 'Failed, the return value is incorrect'
		print '            JWalk MODULE TESTED'
		print ''
		return(1)

if __name__ == "__main__":
  exit (main())

