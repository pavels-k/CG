uniform sampler2D u_texture;
uniform highp float u_lightPower;
varying highp vec4 v_position;
varying highp vec2 v_texcoord;
varying highp vec3 v_normal;
uniform highp vec4 u_lightPosition;
uniform highp float u_absorptionFactor;
uniform highp float u_ambientFactor;
uniform highp float u_specularFactor;

void main(void)
{
    vec4 resultColor = vec4(0.0, 0.0, 0.0, 0.0);
    vec4 eyePosition = vec4(0.0, 0.0, 0.0, 1.0);
//    vec4 diffMatColor = texture2D(u_texture, v_texcoord);
    vec4 diffMatColor = vec4(0.0, 0.2, 0.0, 1.0);
    vec3 eyeVect = normalize(v_position.xyz - eyePosition.xyz);
    vec3 lightVect = normalize(v_position.xyz - u_lightPosition.xyz);
    vec3 reflectLight = normalize(reflect(lightVect, v_normal));
    float len = length(v_position.xyz - eyePosition.xyz);

    vec4 diffColor = diffMatColor * u_lightPower * max(0.0, dot(v_normal, -lightVect))
            / (1.0 + 0.25 * pow(len, 2.0));
    vec4 ambientColor = u_ambientFactor * diffMatColor;
    vec4 specularColor = vec4(1.0, 1.0, 1.0, 1.0) * u_lightPower *
            pow(max(0.0, dot(reflectLight, -eyeVect)), u_specularFactor) / (1.0 + 0.25 * pow(len, 2.0)) * (1.0 - u_absorptionFactor);

    resultColor += diffColor + ambientColor + specularColor;

    gl_FragColor = resultColor;
}
