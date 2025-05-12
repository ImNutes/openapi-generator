package org.openapitools.codegen.languages;

import io.swagger.v3.oas.models.media.Schema;
import io.swagger.v3.parser.util.SchemaTypeUtil;
import org.openapitools.codegen.*;
import org.openapitools.codegen.model.ModelsMap;
import org.openapitools.codegen.model.ModelMap;
import org.openapitools.codegen.model.OperationsMap;
import org.openapitools.codegen.model.OperationMap;
import org.openapitools.codegen.utils.ModelUtils;
import io.swagger.models.properties.ArrayProperty;
import io.swagger.models.properties.MapProperty;
import io.swagger.models.properties.Property;
import io.swagger.models.parameters.Parameter;

import java.io.File;
import java.util.*;

import org.apache.commons.lang3.StringUtils;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class CppNlohmannCprClientCodegen extends AbstractCppCodegen implements CodegenConfig {
    public static final String PROJECT_NAME = "";

    private final Logger LOGGER = LoggerFactory.getLogger(CppNlohmannCprClientCodegen.class);

    public CodegenType getTag() {
        return CodegenType.CLIENT;
    }

    public String getName() {
        return "cpp-nlohmann-cpr";
    }

    public String getHelp() {
        return "Generates a cpp-nlohmann-cpr client.";
    }

    public CppNlohmannCprClientCodegen() {
        super();

        outputFolder = "generated-code" + File.separator + "cpp-nlohmann-cpr";
        modelTemplateFiles.put("model.mustache", ".h");
        apiTemplateFiles.put("api.mustache", ".h");
        embeddedTemplateDir = templateDir = "cpp-nlohmann-cpr";
        apiPackage = "apis";
        modelPackage = "models";
        supportingFiles.add(new SupportingFile("README.mustache", "", "README.md"));
        defaultIncludes = new HashSet<>(
                Arrays.asList(
                        "bool",
                        "int",
                        "long",
                        "double",
                        "float")
        );
        languageSpecificPrimitives = new HashSet<>(
                Arrays.asList(
                        "bool",
                        "int",
                        "long",
                        "double",
                        "float",
                        "std::string")
        );

        typeMapping = new HashMap<>();
        typeMapping.put("string", "std::string");
        typeMapping.put("integer", "int");
        typeMapping.put("boolean", "bool");
        typeMapping.put("array", "std::vector");
        typeMapping.put("map", "std::map");
        typeMapping.put("object", "nlohmann::json");
        typeMapping.put("date-time", "std::string");
        typeMapping.put("DateTime", "std::string");
        typeMapping.put("int64", "long");
        typeMapping.put("long", "long");

        importMapping.put("nlohmann::json", "nlohmann/json.hpp");
        importMapping.put("std::vector", "vector");
        importMapping.put("std::map", "map");
        processOpts();
    }

    @Override
    public String getTypeDeclaration(Schema p) {
        String openAPIType = super.getTypeDeclaration(p);

        if (ModelUtils.isArraySchema(p)) {
            Schema inner = ModelUtils.getSchemaItems(p);
            return super.getTypeDeclaration(p) + "<" + getTypeDeclaration(inner) + ">";
        } else if (ModelUtils.isMapSchema(p)) {
            Schema inner = ModelUtils.getAdditionalProperties(p);
            return super.getTypeDeclaration(p) + "<std::string, " + getTypeDeclaration(inner) + ">";
        } else if (ModelUtils.isFileSchema(p) || ModelUtils.isBinarySchema(p)) {
            return "std::shared_ptr<" + openAPIType + ">";
        } else if (ModelUtils.isStringSchema(p)
                || ModelUtils.isDateSchema(p) || ModelUtils.isDateTimeSchema(p)
                || ModelUtils.isFileSchema(p) || ModelUtils.isUUIDSchema(p)
                || languageSpecificPrimitives.contains(openAPIType)) {
            return openAPIType;
        }

        return "std::shared_ptr<" + openAPIType + ">";
    }

    // @Override
    // public String escapeUnsafeCharacters(String input) {
    //     if (input == null) return null;

    //     return input
    //         .replace("\"", "\\\"")
    //         .replace("\n", "\\n")
    //         .replace("\r", "\\r");
    // }
    @Override
    public String toVarName(String name) {
        String paramName = name.replaceAll("[^a-zA-Z0-9_]", "");
        if (name.length() > 0) {
            paramName = Character.toLowerCase(paramName.charAt(0)) + paramName.substring(1);
        }
        if (isReservedWord(paramName)) {
            return escapeReservedWord(paramName);
        }
        return paramName;
    }
    @Override
    public OperationsMap postProcessOperationsWithModels(OperationsMap objs, List<ModelMap> allModels) {
        for(CodegenOperation op : objs.getOperations().getOperation()) {
                if(op.queryParams != null && op.queryParams.size() != 0) {
                    op.vendorExtensions.put("hasQueryParams", true);
                }
        }
        return super.postProcessOperationsWithModels(objs, allModels);
    }
}
