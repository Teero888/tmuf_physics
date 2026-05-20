import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.PrintWriter;
import java.io.File;
import java.util.Iterator;

public class ListManagers extends GhidraScript {
    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataTypeManager[] allManagers = dtm.getService().getDataTypeManagers();
        
        println("Found " + allManagers.length + " DataTypeManagers");
        for (DataTypeManager m : allManagers) {
            int compositeCount = 0;
            int populatedCount = 0;
            Iterator<DataType> it = m.getAllDataTypes();
            while (it.hasNext()) {
                DataType dt = it.next();
                if (dt instanceof Composite) {
                    compositeCount++;
                    if (((Composite)dt).getNumComponents() > 0) {
                        populatedCount++;
                    }
                }
            }
            println("Manager: " + m.getName() + " - Composites: " + compositeCount + " (Populated: " + populatedCount + ")");
        }
    }
}
