import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DataTypeManager;
import ghidra.program.model.data.DataTypeWriter;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.Composite;
import java.io.PrintWriter;
import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

public class DumpStructs extends GhidraScript {
    @Override
    public void run() throws Exception {
        File outFile = new File(getScriptArgs()[0]);
        PrintWriter writer = new PrintWriter(outFile);
        
        List<DataTypeManager> managers = new ArrayList<>();
        managers.add(currentProgram.getDataTypeManager());
        
        // Find other managers
        DataTypeManager[] allManagers = currentProgram.getDataTypeManager().getService().getDataTypeManagers();
        for (DataTypeManager m : allManagers) {
            if (!managers.contains(m)) {
                managers.add(m);
            }
        }

        writer.println("// Found " + managers.size() + " DataTypeManagers");
        
        for (DataTypeManager dtm : managers) {
            writer.println("// Manager: " + dtm.getName());
            
            try {
                DataTypeWriter dtWriter = new DataTypeWriter(dtm, writer);
                Iterator<DataType> it = dtm.getAllDataTypes();
                while (it.hasNext()) {
                    DataType dt = it.next();
                    // Export anything that is a structure or union and has fields
                    if (dt instanceof Composite) {
                        Composite comp = (Composite)dt;
                        if (comp.getNumComponents() > 0) {
                             dtWriter.write(dt, monitor);
                        }
                    }
                }
            } catch (Exception e) {
                writer.println("// Error writing manager " + dtm.getName() + ": " + e.getMessage());
            }
        }
        
        writer.close();
    }
}
