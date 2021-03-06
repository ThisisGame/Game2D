uniform mat4 m_mvp;
attribute vec3 m_position;
attribute vec2 m_uv;

varying lowp vec2 m_outUV;

void main()
{
	vec4 pos=vec4(m_position,1);
	gl_Position=m_mvp*pos;
	m_outUV=m_uv;
}
