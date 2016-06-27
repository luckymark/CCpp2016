uniform vec2 frag_LightOrigin;
uniform vec2 frag_castPosition1;
uniform vec2 frag_castPosition2;
uniform float frag_shadowAttenuation;

float cross(vec2 a, vec2 b)
{
	return a.x * b.y - a.y * b.x;
}

void main()
{
	float attenuation = frag_shadowAttenuation / (length(frag_LightOrigin - gl_FragCoord.xy));
	if (cross(gl_FragCoord.xy - frag_LightOrigin, frag_castPosition1 - frag_LightOrigin) *
		cross(gl_FragCoord.xy - frag_LightOrigin, frag_castPosition2 - frag_LightOrigin) < 0 &&
		cross(frag_castPosition2 - frag_castPosition1, frag_LightOrigin - frag_castPosition1) *
		cross(frag_castPosition2 - frag_castPosition1, gl_FragCoord.xy - frag_castPosition1) < 0)
	{
		gl_FragColor = vec4(0, 0, 0, attenuation);
	}
	else
	{
		gl_FragColor = vec4(0, 0, 0, 0.0);
	}
}
