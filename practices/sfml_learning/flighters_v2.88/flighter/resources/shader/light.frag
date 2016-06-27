uniform vec2 frag_LightOrigin;
uniform vec4 frag_LightColor;
uniform float frag_LightAttenuation;

void main()
{
	float attenuation = 1.0 / (frag_LightAttenuation * length(frag_LightOrigin - gl_FragCoord.xy));
	gl_FragColor = vec4(attenuation, attenuation, attenuation, 1.0) * frag_LightColor;
}