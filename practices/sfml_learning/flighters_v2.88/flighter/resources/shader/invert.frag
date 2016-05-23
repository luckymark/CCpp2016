uniform sampler2D texture;

void main()
{
	vec4 ref = texture2D(texture, gl_TexCoord[0].xy);
	gl_FragColor = (vec4(1.0, 1.0, 1.0, 1.0) - ref) * gl_Color;
	gl_FragColor.a = ref.a;
}