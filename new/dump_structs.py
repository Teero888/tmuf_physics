from ghidra.program.model.data import Composite, DataTypeWriter
import java.io.File
import java.io.PrintWriter

def run():
    args = getScriptArgs()
    if not args:
        print("Please provide output file path as argument")
        return
        
    out_file = java.io.File(args[0])
    writer = java.io.PrintWriter(out_file)
    
    dtm = currentProgram.getDataTypeManager()
    managers = [dtm]
    
    # Try to get other managers
    service = dtm.getService()
    if service:
        all_managers = service.getDataTypeManagers()
        for m in all_managers:
            if m not in managers:
                managers.append(m)
                
    writer.println("// Found %d DataTypeManagers" % len(managers))
    
    for dtm in managers:
        writer.println("// Manager: %s" % dtm.getName())
        dt_writer = DataTypeWriter(dtm, writer)
        
        datatypes = dtm.getAllDataTypes()
        count = 0
        while datatypes.hasNext():
            dt = datatypes.next()
            if isinstance(dt, Composite):
                if dt.getNumComponents() > 0:
                    dt_writer.write(dt, monitor)
                    count += 1
        writer.println("// Exported %d composites from %s" % (count, dtm.getName()))
        
    writer.close()
    print("Done exporting to %s" % args[0])

if __name__ == '__main__':
    run()
