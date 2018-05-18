import psutil
import time
import sys


def main():
    process_id = sys.argv[1]
    proc = psutil.Process(int(process_id))
    if(int(process_id) == int(proc.pid)):
        name = proc.name()
        status = proc.status()
        parent_id = proc.ppid()
        parent_name = psutil.Process(proc.ppid()).name()
        create_date = proc.create_time()
        files = proc.open_files()
        memory = proc.memory_info()
        print("Process Id : " + str(proc.pid))
        print("Process name : " + name)
        print("Process Status : " + status)
        print("Process Parent ID : " + str(parent_id))
        print("Process Parent Name : " + str(parent_name))
        print("Process create time: "+ str(time.ctime(create_date)))
        print("Files opened : " + str(files))
        print("Memory Info : " + str(memory[0]))

if __name__ == "__main__":
    main()